
ScriptPath=$(cd `dirname $0`; pwd)
adb remount
adb push $ScriptPath/gtool /system/bin 
adb shell cd /system/bin/

