
BASEDIR=$(dirname "$0")
python2 $BASEDIR/gennums.py $1 > out

xclip -sel c < out

rm out
