#!/usr/bin/env bash

if ln ex2.txt ex2.txt.lock; then
	sh ex2.sh
	rm ex2.txt.lock;
fi
