import com.sun.jna.Library;
import com.sun.jna.Native;
import com.sun.jna.Platform;
import com.sun.jna.Pointer;

public class demo {
	public interface TestDll extends Library {

        /**
         * 当前路径是在项目下，而不是bin输出目录下。
         */
        TestDll INSTANCE = (TestDll)Native.load("OCRProof_x64", TestDll.class);

        public int OCRProof_Init();
        public Pointer OCRProof_NewInstance(String outputDir, String exeDir);
        public void OCRProof_Exit(Pointer p);
        public boolean OCRProof_convert2TXT(Pointer p, String filePath);
        public void OCRProof_setConvertexeDir(Pointer p, String path);
        public void OCRProof_setOutputDir(Pointer p, String path);
        public void OCRProof_Combine(Pointer p, String filePath, boolean isRemove);
	}
	public static void main(String[] args) {
		// TODO Auto-generated method stub
	    String[] files = {
	    		"E:\\tmp\\proof_in\\img\\test_Page_1.jpg",
	            "E:\\tmp\\proof_in/img\\test_Page_2.jpg",
	    	    "E:\\tmp\\proof_in\\img\\test_Page_3.jpg",
		};
	    if(1 != TestDll.INSTANCE.OCRProof_Init())
	    {
	    	System.out.println("初始化失败");
	        return;
	    }
	    Pointer p = TestDll.INSTANCE.OCRProof_NewInstance("E:\\tmp\\proof_out", 
	    		"E:\\code\\GIT\\CallOCRDLLDemo\\tesseract");
	    if(p == null)
	    {
	    	System.out.println("创建实例失败");
	    	return;
	    }

	    //下面的代码可以覆盖Compare_NewInstance时指定的路径，在运行中可随时更改
//	    TestDll.INSTANCE.setConvertexeDir(p, "E:\\code\\GIT/");
//	    TestDll.INSTANCE.setOutputDir(p, "E:\\tmp\\contract_out");

	    long startTime=System.currentTimeMillis();

	    for(String path:files)
	    {
	    	System.out.printf("%s 开始处理\n", path);
	        if(!TestDll.INSTANCE.OCRProof_convert2TXT(p, path))
//	            System.out.printf("%s OCR完成\n", path);
//	        else
	        	System.out.printf("%s OCR失败\n", path);
	    }
	    TestDll.INSTANCE.OCRProof_Combine(p, 
	    		"E:\\tmp\\proof_out\\test_Page.txt", false);

	    System.out.printf("分析耗时：%f s\n", 
	    		(System.currentTimeMillis() - startTime) / 1000.0);
	    TestDll.INSTANCE.OCRProof_Exit(p);
	}

}
