#ifndef TEST_IMAGE_GENERATOR_H
#define TEST_IMAGE_GENERATOR_H

#include <lms/module.h>
#include <lms/imaging/image.h>

/**
 * @brief LMS module test_image_generator
 **/
class TestImageGenerator : public lms::Module {
public:
    bool initialize() override;
    bool deinitialize() override;
    bool cycle() override;
private:
    lms::WriteDataChannel<lms::imaging::Image> m_image;
};

#endif // TEST_IMAGE_GENERATOR_H
