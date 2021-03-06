package android.os;

/** {@hide} */
interface ILedService
{
  int LedCtrl(int which,int status);
}

/* 所在路径 frameworks\base\core\java\android\os */

/* 修改frameworks/base/Android.mk  */

/* 执行 mmm 命令 在frameworks/base 目录下执行 mmm . */

/* 编译结果会放在   find -name "ILedService.java"
	out/target/common/obj/JAVA_LIBRARIES/framework_intermediates/src/core/java/android/os/ILedService.java
 */
 
 /*
 	app 使用： ILedService iLedService;
 		   iLedService = ILedService.Stub.asInterface(ServiceManager.getService("Led"));
 		   
 		  iLedService.LedCtrl(int which,int status);
  */