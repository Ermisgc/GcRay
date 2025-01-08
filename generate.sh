#!/bin/bash

# compilation
mkdir -p build
cd ./build
cmake ..
make

# run the GcRay in the directory which we want to contain the .pov files
cd ../bin/falanguanban3
../GcRay

# the directory that containing .pov files
pov_dir="."

# the output directory
output_dir="./output"

# make sure the directory is exist
mkdir -p "$output_dir"

# tranverse all the .pov files
for pov_file in "$pov_dir"/*.pov; do
    # 获取文件名（不包含路径）
    filename=$(basename "$pov_file")
    # 获取文件名（不包含扩展名）
    base_filename="${filename%.*}"
    
    # run POV-Ray with the rendering parameters
    povray +W1024 +H960 +O"$output_dir/$base_filename.png" +I"$pov_file"
    
    # 输出渲染状态信息
    echo "Rendered $base_filename.png"
done

echo "All files rendered and saved to $output_dir"