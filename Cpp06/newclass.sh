#!/bin/sh
# newclass.sh — generate Class.hpp / Class.cpp in Orthodox Canonical Form
# Usage: ./newclass.sh ClassName [--force] [--inc include_dir] [--src src_dir]

set -eu

if [ $# -lt 1 ]; then
  echo "Usage: $0 ClassName [--force] [--inc include_dir] [--src src_dir]" >&2
  exit 1
fi

CLASS="$1"
shift || true

FORCE=0
INC_DIR="."
SRC_DIR="."

# parse options
while [ $# -gt 0 ]; do
  case "$1" in
    --force) FORCE=1; shift ;;
    --inc)   [ $# -ge 2 ] || { echo "Missing arg for --inc" >&2; exit 1; }
             INC_DIR="$2"; shift 2 ;;
    --src)   [ $# -ge 2 ] || { echo "Missing arg for --src" >&2; exit 1; }
             SRC_DIR="$2"; shift 2 ;;
    *) echo "Unknown option: $1" >&2; exit 1 ;;
  esac
done

# sanitize guard: UPPERCASE + _HPP, non-alnum -> _
GUARD=$(printf "%s" "${CLASS}_HPP" | tr '[:lower:]' '[:upper:]' | sed 's/[^A-Z0-9_]/_/g')

# ensure dirs exist
mkdir -p "$INC_DIR" "$SRC_DIR"

HPP="${INC_DIR%/}/${CLASS}.hpp"
CPP="${SRC_DIR%/}/${CLASS}.cpp"

write_file() {
  # $1 = path ; $2 = type (hpp|cpp)
  path="$1"
  kind="$2"
  if [ -e "$path" ] && [ "$FORCE" -ne 1 ]; then
    echo "Refusing to overwrite $path (use --force)" >&2
    return 0
  fi

  if [ "$kind" = "hpp" ]; then
    # variable expansion ON (no quotes around EOF) to expand $CLASS and $GUARD
    cat >"$path" <<EOF
#ifndef $GUARD
#define $GUARD

#include <iostream>

class $CLASS {
public:

    $CLASS();
    $CLASS(const $CLASS& other);
    $CLASS& operator=(const $CLASS& rhs);
    ~$CLASS();

private:

};

#endif // $GUARD
EOF
  else
    cat >"$path" <<EOF
#include "$CLASS.hpp"


$CLASS::$CLASS()
{

}

$CLASS::$CLASS(const $CLASS& other)
{

}

$CLASS& $CLASS::operator=(const $CLASS& src)
{
    if (this != &src)
	{

    }
    return *this;
}

$CLASS::~$CLASS()
{

}
EOF
  fi

  echo "Created $path"
}

write_file "$HPP" hpp
write_file "$CPP" cpp

echo "Done."
