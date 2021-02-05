#ifndef VEHICLEDETECTOR_H
#define VEHICLEDETECTOR_H
#include <iostream>
#include <opencv2/core.hpp>
#include <opencv2/imgproc.hpp>
#include <tensorflow/lite/model.h>
#include <tensorflow/lite/model_builder.h>
#include <tensorflow/lite/kernels/register.h>

class VehicleDetector
{
public:
    VehicleDetector();
    VehicleDetector(const char *tflitemodel, bool quantized = false);
private:
    const int DETECTION_MODEL_SIZE = 320;
    const int DETECTION_MODEL_CHANNELS = 3;
    const float IMAGE_MEAN = 128.0;
    const float IMAGE_STD = 128.0;
    const char *WEIGHTS_PATH = std::getenv("WEIGHTS_FILE");
    bool m_modelQuantized = false;
    bool m_hasDetectionModel = false;
    char *m_modelBytes = nullptr;
    std::unique_ptr<tflite::FlatBufferModel> m_model;
    std::unique_ptr<tflite::Interpreter> m_interpreter;
    TfLiteTensor *m_input_tensor = nullptr;
    TfLiteTensor *m_output_locations = nullptr;
    TfLiteTensor *m_output_classes = nullptr;
    TfLiteTensor *m_output_scores = nullptr;
    TfLiteTensor *m_num_detections = nullptr;

    // init detection model
    void initDetectionModel(const char *tfliteModel);
};

#endif // VEHICLEDETECTOR_H
