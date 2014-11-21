package org.ec8.ec8top;

import android.app.Activity;
import android.os.Bundle;

public class MainActivity extends Activity
{
    /** Called when the activity is first created. */
    @Override
    public void onCreate(Bundle savedInstanceState)
    {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.main);

        Thread thread = new Thread(){
           public void run(){
              startHTTP();
           }
        };
        thread.start();

    }

    private native String startHTTP();

    static {
        System.loadLibrary("ec8top");
    }
}
