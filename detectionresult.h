#ifndef DETECTIONRESULT_H
#define DETECTIONRESULT_H
#include <vector>
#include <string>


class DetectionResult
{
public:
    DetectionResult();

    //Setters
    void setDetectionLabel(int label);
    void setDetectionScore(float score);
    void setDetectionYmin(float ymin);
    void setDetectionXmin(float xmin);
    void setDetectionYmax(float ymax);
    void setDetectionXmax(float xmax);

    //Getters

    // methods

    std::string SerializeDetection();

private:
    std::vector<int> label;
    std::vector<float> score;
    std::vector<float> ymin;
    std::vector<float> xmin;
    std::vector<float> ymax;
    std::vector<float> xmax;
};

#endif // DETECTIONRESULT_H
