package android.os;

/** {@hide} */
interface ILedService
{
  int LedCtrl(int which,int status);
}

/* ����·�� frameworks\base\core\java\android\os */

/* �޸�frameworks/base/Android.mk  */

/* ִ�� mmm ���� ��frameworks/base Ŀ¼��ִ�� mmm . */

/* �����������   find -name "ILedService.java"
	out/target/common/obj/JAVA_LIBRARIES/framework_intermediates/src/core/java/android/os/ILedService.java
 */
 
 /*
 	app ʹ�ã� ILedService iLedService;
 		   iLedService = ILedService.Stub.asInterface(ServiceManager.getService("Led"));
 		   
 		  iLedService.LedCtrl(int which,int status);
  */