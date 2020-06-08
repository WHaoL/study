#!/bin/bash

echo "Is it morning? Please answer yes or no."
read YES_OR_NO
case "$YES_OR_NO" in
    [Yy]|Yes|yes|YES)
        echo "Good morning"
        ;;
    [Nn][Oo])
        echo "Good afternoon"
        ;;
    *)
        echo "Please answer yes or no"
        ;;
esac

