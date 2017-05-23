
package com.android.server;
import android.os.ILedService;


public class LedService extends ILedService.Stub{
    private static final String TAG = "LedService";
    /* 作用是调用本地方法操作硬件 call native function to access hardware */
    public int LedCtrl(int which, int status) throws android.os.RemoteException
    {
    	return native_ledCtrl(which,status);
    }
    
    
    public LedService()
    {
    	native_ledOpen();
    }
    
    public int native native_ledOpen();
    public void native native_ledClose();
    public int native native_ledCtrl(int which,int status);
    
}