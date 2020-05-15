#!/bin/bash
echo "Is it morning? Please answer yes or no."
read YES_OR_NO
case "$YES_OR_NO" in
yes|[Yy]|YES)
    echo "Good mmorning!" ;;
[nN]|[Oo])
    echo "Good afternoon!" ;;
*)
    echo "please input yes or no."
esac
