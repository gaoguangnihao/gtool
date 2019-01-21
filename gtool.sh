

echo "My name is `basename $0` -I was called as $0"
ScriptPath=$(cd `dirname $0`; pwd)
echo "ScriptPath " $ScriptPath
if [ ! -n "$1" ] ;then
    echo "you have not input a word!"
else
    cp $ScriptPath/../$1/out/target/product/gflip2/system/bin/gtool $ScriptPath
    echo "copy bin file ok"
    if [ ! -n "$2" ] ;then
    	echo "do not copy src"
    else
    	cp -r $ScriptPath/../$1/system/core/gtool $ScriptPath/$2
    	cp $ScriptPath/gtool $ScriptPath/$2
    	echo "copy src file ok"
    fi
fi

adb remount
adb push $ScriptPath/gtool /system/bin 
adb shell cd /system/bin/

