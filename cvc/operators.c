#include <stdio.h>
#include <cv.h>
#include <highgui.h>
 
int main( int argc, char **argv ){
    IplImage *surfer, *milkyway, *result;
    int key = 0;
    CvSize size;
 
    /* load images, check, get size (both should have the same) */
    surfer = cvLoadImage("surfer.jpg", CV_LOAD_IMAGE_COLOR);
    milkyway = cvLoadImage("milkyway.jpg", CV_LOAD_IMAGE_COLOR);
    if((!surfer)||(!milkyway)){
        printf("Could not open one or more images.");
        exit -1;
    }
    size = cvGetSize(surfer);
 
    /* create a empty image, same size, depth and channels of others */
    result = cvCreateImage(size, surfer->depth, surfer->nChannels);
    cvZero(result);
 
    /* result = surfer + milkyway (NULL mask)*/
    cvAdd(surfer, milkyway, result, NULL);
 
    /* create a window, display the result, wait for a key */
    cvNamedWindow("example", CV_WINDOW_AUTOSIZE);
    cvShowImage("example", result);
    cvWaitKey(0);
 
    /* free memory and get out */
    cvDestroyWindow("example");
    cvReleaseImage(&surfer);
    cvReleaseImage(&milkyway);
    cvReleaseImage(&result);
    return 0;
}
