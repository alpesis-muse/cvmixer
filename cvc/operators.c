#include <stdio.h>

#include <cv.h>  
#include <highgui.h>  
 
 
int main(int argc, char** argv)  
{  
    IplImage * src1 = cvLoadImage("1.jpg");
    IplImage * src2 = cvLoadImage("3.jpg");  
    IplImage * src3 = cvLoadImage("4.jpg");  
    cvAdd(src1, src2, src2); 
    cvShowImage( "测试1", src1);  
    cvShowImage( "测试2", src2);  
    cvShowImage( "测试3", src3);  
    cvWaitKey(0);  
    return 0;  
} 
