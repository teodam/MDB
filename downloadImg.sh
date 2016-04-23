#!/bin/bash

mkdir DB

#Level 1
mkdir DB/lvl1
URL=`grep -o /data/logoquiz/images/.*.png sourceweb/level-1.html | awk 'NR % 2 == 0' | awk '{print "http://logosquiz.info"$0}'`
echo "============================="
echo $URL
echo "============================="
for var in $URL
do
	nom=`echo $var | cut -d '/' -f 7 | cut -d '_' -f 1 | awk '{print $0".png"}'`
	wget $var -O DB/lvl1/$nom
done

#Level 2
mkdir DB/lvl2
URL=`grep -o /data/logoquiz/images/.*.png sourceweb/level-2.html | awk 'NR % 2 == 0' | awk '{print "http://logosquiz.info"$0}'`
echo "============================="
echo $URL
echo "============================="
for var in $URL
do
	nom=`echo $var | cut -d '/' -f 7 | cut -d '_' -f 1 | awk '{print $0".png"}'`
	wget $var -O DB/lvl2/$nom
done

#Level 3
mkdir DB/lvl3
URL=`grep -o /data/logoquiz/images/.*.png sourceweb/level-3.html | awk 'NR % 2 == 0' | awk '{print "http://logosquiz.info"$0}'`
echo "============================="
echo $URL
echo "============================="
for var in $URL
do
	nom=`echo $var | cut -d '/' -f 7 | cut -d '_' -f 1 | awk '{print $0".png"}'`
	wget $var -O DB/lvl3/$nom
done

#Level 4
mkdir DB/lvl4
URL=`grep -o /data/logoquiz/images/.*.png sourceweb/level-4.html | awk 'NR % 2 == 0' | awk '{print "http://logosquiz.info"$0}'`
echo "============================="
echo $URL
echo "============================="
for var in $URL
do
	nom=`echo $var | cut -d '/' -f 7 | cut -d '_' -f 1 | awk '{print $0".png"}'`
	wget $var -O DB/lvl4/$nom
done

#Level 5
mkdir DB/lvl5
URL=`grep -o /data/logoquiz/images/.*.png sourceweb/level-5.html | awk 'NR % 2 == 0' | awk '{print "http://logosquiz.info"$0}'`
echo "============================="
echo $URL
echo "============================="
for var in $URL
do
	nom=`echo $var | cut -d '/' -f 7 | cut -d '_' -f 1 | awk '{print $0".png"}'`
	wget $var -O DB/lvl5/$nom
done