#! /bin/bash

set -e
# create directory to store files produced by compiler
build_dir=build
if [ -d "${build_dir}" ]; then
    rm -rf ${build_dir}
fi
mkdir -p ${build_dir}

# compile 
cd ${build_dir}
cmake .. -DCMAKE_BUILD_TYPE=Release
make -j6
cd ..
echo "compile finished"
