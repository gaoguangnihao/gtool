
/**
* Aughter by guang.gao
*/


package com.android.gtool;

import android.app.ActivityManager;
import android.app.ActivityManager.StackInfo;
import android.app.ActivityManagerNative;
import android.app.IActivityContainer;
import android.app.IActivityController;
import android.app.IActivityManager;
import android.app.IInstrumentationWatcher;
import android.app.Instrumentation;
import android.app.IStopUserCallback;
import android.app.ProfilerInfo;
import android.app.UiAutomationConnection;
import android.app.usage.ConfigurationStats;
import android.app.usage.IUsageStatsManager;
import android.app.usage.UsageStatsManager;
import android.content.ComponentCallbacks2;
import android.content.ComponentName;
import android.content.Context;
import android.content.IIntentReceiver;
import android.content.Intent;
import android.content.pm.IPackageManager;
import android.content.pm.ParceledListSlice;
import android.content.pm.ResolveInfo;
import android.content.res.Configuration;
import android.graphics.Rect;
import android.net.Uri;
import android.os.Binder;
import android.os.Build;
import android.os.Bundle;
import android.os.ParcelFileDescriptor;
import android.os.RemoteException;
import android.os.SELinux;
import android.os.ServiceManager;
import android.os.SystemClock;
import android.os.SystemProperties;
import android.os.UserHandle;
import android.text.TextUtils;
import android.util.AndroidException;
import android.util.ArrayMap;
import android.util.Log;
import android.view.IWindowManager;

import com.android.internal.os.BaseCommand;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintStream;
import java.net.URISyntaxException;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.HashSet;
import java.util.List;

public class GtoolCommand extends BaseCommand {
    /**
     * Command-line entry point.
     *
     * @param args The command-line arguments
     */
    public static void main(String[] args) {
        (new GtoolCommand()).run(args);
    }

     @Override
    public void onShowUsage(PrintStream out) {
        out.println(
                "usage: am [subcommand] [options]\n"
                );
    }

     @Override
    public void onRun() throws Exception {
        Log.v("gtool","GtoolCommand");
    }
}
