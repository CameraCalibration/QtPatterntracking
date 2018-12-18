#ifndef PATTERNDETECTOR_H
#define PATTERNDETECTOR_H

#include <QObject>
#include <iostream>
#include <string>
#include <sstream>
#include <opencv2/opencv.hpp>

class MainWindow;
//class TrackingGrid;

class PatternDetector : public QObject
{
    Q_OBJECT
public:
    explicit PatternDetector(QObject *parent = nullptr);
    void setCurrentPattern(unsigned int pattType);
    unsigned int getCurrentPattern();
    void setImage(cv::Mat im);
    void setVisualizer(MainWindow *vis);
    void setSizePattern(int nRows, int nCols);
    bool processingRingsPattern(std::vector<cv::Point2f> &keypoints);
    void initProcessing(unsigned int pattSelected);

private:
    cv::Mat adaptiveThresholdIntegralImage(cv::Mat input);
    std::vector<cv::Point2f> cleanNoiseCenters(std::vector<cv::Point2f> vCenters, std::vector<std::pair<float, int> > vRadius, int maxError=0);
    std::vector<cv::Point2f> findROI_rings(cv::Mat image, cv::Mat &imgOut);
    bool trackingRingsPoints(std::vector<cv::Point2f>&);
    std::vector<cv::Point2f> ordenar(std::vector<cv::Point2f> centros);

public:
signals:

public slots:

private:
    cv::Mat img;
    unsigned int currentPattern;
    unsigned int numCols;
    unsigned int numRows;
    MainWindow *visualizer;

    //TrackingGrid* trackGrid;
    double radioOptimo;

    bool foundFirstPattern;
    std::vector<cv::Point2f> patternBefore;
    std::vector<cv::Point2f> patternActual;
    std::pair<float,float> centNextPred;
};

#endif // PATTERNDETECTOR_H
