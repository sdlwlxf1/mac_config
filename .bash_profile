
# JAVA
# export JAVA_HOME=/usr/libexec/java_home -v 1.8

export NDK_ROOT=/Users/tuyoo/Library/Android/ndk/android-ndk-r10d
export ANDROID_SDK_ROOT=/Users/tuyoo/Library/Android/sdk
export ANDROID_HOME=/Users/tuyoo/Library/Android/sdk
export PATH=$NDK_ROOT:$ANDROID_SDK_ROOT:$PATH

# Add environment variable COCOS_CONSOLE_ROOT for cocos2d-x
export COCOS_CONSOLE_ROOT=/Applications/Cocos/Cocos2d-x/cocos2d-x-3.10/tools/cocos2d-console/bin
export PATH=$COCOS_CONSOLE_ROOT:$PATH

# Add environment variable COCOS_X_ROOT for cocos2d-x
export COCOS_X_ROOT=/Applications/Cocos/Cocos2d-x
export PATH=$COCOS_X_ROOT:$PATH

# Add environment variable COCOS_TEMPLATES_ROOT for cocos2d-x
export COCOS_TEMPLATES_ROOT=/Applications/Cocos/Cocos2d-x/cocos2d-x-3.10/templates
export PATH=$COCOS_TEMPLATES_ROOT:$PATH

# Add environment variable COCOS_CONSOLE_ROOT for cocos2d-x
export COCOS_CONSOLE_ROOT=/Users/tuyoo/Documents/cocos2d-x-3.9/tools/cocos2d-console/bin
export PATH=$COCOS_CONSOLE_ROOT:$PATH

# Add environment variable COCOS_TEMPLATES_ROOT for cocos2d-x
export COCOS_TEMPLATES_ROOT=/Users/tuyoo/Documents/cocos2d-x-3.9/templates
export PATH=$COCOS_TEMPLATES_ROOT:$PATH

# MacPorts Installer addition on 2016-06-17_at_00:41:06: adding an appropriate PATH variable for use with MacPorts.
export PATH="/opt/local/bin:/opt/local/sbin:$PATH"
# Finished adapting your PATH environment variable for use with MacPorts.

# ADB
export PATH=$ANDROID_HOME/platform-tools:$ANDROID_HOME/tools:$PATH

# NODE
export NODE_PATH=/usr/local/lib/node_modules
export PATH=$NODE_PATH:$PATH

# GRADLE
export GRADLE_HOME=/Users/tuyoo/Library/gradle/gradle-3.4.1
export PATH=$GRADLE_HOME/bin:$PATH

# TexturePack
export TEXTUREPACK=/Applications/TexturePacker.app/Contents/MacOS
export PATH=$TEXTUREPACK:$PATH

# SVN_EDITOR
export SVN_EDITOR=vim

# copy pwd to clipboard
cpath(){
    echo -n "$(pwd)"/"$1"|pbcopy
}
