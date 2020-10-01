# Issues

## Crash | Show Toast 

When a toast was shown in a method inside `gameActivityClassAdditions` it would crash, but
not if it was in `gameActivityOnResumeAdditions`.

Encapsulating it in `runOnUiThread` prevented it from crashing in `gameActivityClassAdditions`.

    runOnUiThread(new Runnable(){
        public void run()
	{
	}
    });

Reference: https://isaratech.com/ue4-making-a-android-plugin-in-10-minutes/


