#include "cameracalibrator.h"
#include "patterndetector.h"
#include "mainwindow.h"
#include "constants.h"
#include <time.h>
#include <iterator>
#include <set>
#include <fstream>

CameraCalibrator::CameraCalibrator(QObject *parent) : QObject(parent)
{
    pattDetector = new PatternDetector();
    actived = true;
    clearCalibrationInputs();
}

///
/// \brief CameraCalibrator::setVisualizer asigna el visualizador que se usara para el procesamiento
/// \param vis  MainWindow donde se visualizara los videos
///
void CameraCalibrator::setVisualizer(MainWindow *vis)
{
    visualizer = vis;
    pattDetector->setVisualizer(vis);
}

///
/// \brief CameraCalibrator::setActived setea el estado del procesamiento
/// \param act  Nuevo estado del procesamiento
///
void CameraCalibrator::setActived(bool act)
{
    actived = act;
}

void CameraCalibrator::setCurrentCalibrator(unsigned int calib)
{
    currCalib = calib;
}

///
/// \brief CameraCalibrator::setSizePattern setea el tamaño del patrón
/// \param nRows    Numero de filas que tiene el patron
/// \param nCols    Numero de columnas que tiene el patron
///
void CameraCalibrator::setSizePattern(int nRows, int nCols)
{
    numRows = nRows;
    numCols = nCols;
    pattDetector->setSizePattern(nRows, nCols);
}

///
/// \brief CameraCalibrator::loadVideo se carga el video a partir de la ruta asignada
/// \param path     Ruta donde se encuentra el video
/// \return   Bool que indica si el video se cargo correctamente o no
///
bool CameraCalibrator::loadVideo(std::string path)
{
    pathVideo = path;
    video.open(path);
    if (!video.isOpened())
        return false;
    return true;
}

///
/// \brief CameraCalibrator::processingPattern realiza el procesamiento para la calibracion del patrón
///
void CameraCalibrator::processingPattern()
{
    //Variable tiempo
    cv::TickMeter tm;
    // Variables auxiliares
    cv::Mat img, tmp;
    int framesTotal = 0, framesAnalyzed = 0;
    bool status = false;
    std::map<uint, std::vector<cv::Point2f> > mapFrames;
    std::vector<float> distances;

    while (true && actived) {
        // Lectura de cada frame
        video >> img;
        if (!img.data)
            break;
        framesTotal++;

        std::vector<cv::Point2f> keypoints;
        tmp = img.clone();
        pattDetector->setImage(tmp);
        switch (pattDetector->getCurrentPattern()) {
            case PATT_RING:
                tm.start();
                status = pattDetector->processingRingsPattern(keypoints);
                tm.stop();
                break;
        }
        // preguntamos si encontro el patron
        if(status) {
            framesAnalyzed++;
            mapFrames[framesTotal] = keypoints;
            //imwrite(folderOutVideo + "/frame_" + num2str<int>(framesTotal) + ".png", tmp);
        }
        else {
            //imwrite(folderOutVideo + "/frame_" + num2str<int>(framesTotal) + "_mal.png", tmp);
            continue; // Pasamos al siguiente frame
        }

        if (cv::waitKey(10) >= 0)
            break;
    }
    std::cout<<"TM get counter"<<tm.getCounter();
    double average_time = tm.getTimeMilli() / tm.getCounter();

    std::cout << "=====================\n";
    std::cout << "Total Frames: " << framesTotal << "\nFrames Analizados: " << framesAnalyzed << "\n% Analisis: " << (framesAnalyzed * 1.0 / framesTotal) << "\n AVG: "<<average_time<< std::endl;
    std::cout << "=====================\n";

}

///
/// \brief CameraCalibrator::initProcessing inicia el proceso de calibración de la cámara
///
void CameraCalibrator::initProcessing(unsigned int pattSelected)
{
    visualizer->cleanImage(PROC1);
    visualizer->cleanImage(PROC2);
    visualizer->cleanImage(PROC3);
    visualizer->cleanImage(PROC4);
    visualizer->cleanImage(PROCFIN);

    pattDetector->setCurrentPattern(pattSelected);

    switch (pattSelected) {
    case PATT_CIRCLE:
        folderOutVideo = pathVideo.substr(pathVideo.size()-21, 17);
        break;
    case PATT_RING:
        folderOutVideo = pathVideo.substr(pathVideo.size()-20, 16);
        break;
    }
    processingPattern();
    clearCalibrationInputs();
}

///
/// \brief CameraCalibrator::clearCalibrationInputs limpia los parámetros de calibración
///
void CameraCalibrator::clearCalibrationInputs()
{
    /*isCalibrated = false;
    distanceKeypoints = 0;
    numFramesToCalibration = 0;
    pathOutput = "";
    calibFixPrincipalPoint = false;
    calibFixAspectRatio = false;
    calibZeroTangentDist = true;
    saveCamParams = false;*/
}
