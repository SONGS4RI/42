#!/bin/bash

# Specify the directory to delete files from.
directory="/Users/jahlee/Library/Caches/vscode-cpptools/ipch"

# Get the current time as an integer.
current_time_int=$(date +"%H%M")

# If the current time is divisible by 10, delete the files from the directory.
if [[ $(($current_time_int % 10)) == 0 ]]; then
  echo "Deleting files from $directory."
  rm -rf $directory/*
fi