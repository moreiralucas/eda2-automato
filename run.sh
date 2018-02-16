#!/bin/bash
for i in `seq 1 10`;
do
	./execute.out > output$i
done
