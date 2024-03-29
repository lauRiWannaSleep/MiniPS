#pragma once

#include "Comman/Comman.h"
#include <opencv2/opencv.hpp>
#include <QtGui/QImage>

class Model;
class OpenFileCommand;
class IPropertyNotification;

class ViewModel
{
private:
    std::shared_ptr<QImage> qimg_origin;
    std::shared_ptr<cv::Mat> cvimg_origin;
	std::shared_ptr<QImage> qimg_changed;
	std::shared_ptr<cv::Mat> cvimg_changed;
	std::shared_ptr<QImage> qimg_back;
	std::shared_ptr<cv::Mat> cvimg_back;

    std::shared_ptr<Model> model;
public:
    
    std::shared_ptr<IPropertyNotification> convertImageFormatSink;
    std::shared_ptr<IPropertyNotification> updateViewNotifier;

	std::shared_ptr<ICommandBase> openFileCommand;
	std::shared_ptr<ICommandBase> contrastCommand;
	std::shared_ptr<ICommandBase> gaussianFilterCommand;
	std::shared_ptr<ICommandBase> brightCommand;
	std::shared_ptr<ICommandBase> saveFileCommand;
	std::shared_ptr<ICommandBase> filter1Command;
	std::shared_ptr<ICommandBase> filter2Command;
    std::shared_ptr<ICommandBase> faceDetectCommand;

public:
    ViewModel();
    void bind(std::shared_ptr<Model> model);
    void SetUpdateViewNotifier(std::shared_ptr<IPropertyNotification>);
    std::shared_ptr<IPropertyNotification> GetConvertImageFormatSink();

    void ConvertImageFormat();
    QImage MatToQImage(cv::Mat);

    std::shared_ptr<QImage> GetQImage_origin();
    void SetCvImage_origin(std::shared_ptr<cv::Mat>);
	std::shared_ptr<QImage> GetQImage_changed();
	void SetCvImage_changed(std::shared_ptr<cv::Mat>);
	std::shared_ptr<QImage> GetQImage_back();
	void SetCvImage_back(std::shared_ptr<cv::Mat>);

	void ExecOpenFileCommand(std::string&);
	void ExecContrastCommand(double,double);
	void ExecGaussianFilterCommand();
	void ExecBrightCommand(double);
	void ExecSaveFileCommand(std::string&);
	void ExecFilter1Command();
	void ExecFilter2Command();
    void ExecFaceDetectCommand();

	std::shared_ptr<ICommandBase> GetOpenFileCommand();
	std::shared_ptr<ICommandBase> GetContrastCommand();
	std::shared_ptr<ICommandBase> GetGaussianFilterCommand();
	std::shared_ptr<ICommandBase> GetBrightCommand();
	std::shared_ptr<ICommandBase> GetSaveFileCommand();
	std::shared_ptr<ICommandBase> GetFilter1Command();
	std::shared_ptr<ICommandBase> GetFilter2Command();
    std::shared_ptr<ICommandBase> GetFaceDetectCommand();
};
