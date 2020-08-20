#!/bin/bash

pushd $(dirname $0) > /dev/null

# Required by window.hpp
if [[ ${OSTYPE} == "linux-gnu"* ]]; then
   HYDE_COMPILER_ARGS="-DELEMENTS_HOST_UI_LIBRARY_GTK=1"
elif [[ ${OSTYPE} == "darwin"* ]]; then
   HYDE_COMPILER_ARGS="-DELEMENTS_HOST_UI_LIBRARY_COCOA=1"
fi

HYDE_ARGS="--hyde-update --access-filter-public --use-system-clang"

hyde ${HYDE_ARGS} lib/include/elements/app.hpp -- ${HYDE_COMPILER_ARGS}

popd > /dev/null
