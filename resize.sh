#!/bin/bash

for file in DB/lvl1/*
do
	echo $file
	mogrify -resize 500x500 $file
done
