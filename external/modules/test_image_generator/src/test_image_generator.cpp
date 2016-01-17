#include "test_image_generator.h"
#include <lms/imaging/graphics.h>

bool TestImageGenerator::initialize() {
    m_image = writeChannel<lms::imaging::Image>("IMAGE");
    m_image->resize(640, 480, lms::imaging::Format::BGRA);
    return true;
}

bool TestImageGenerator::deinitialize() {
    return true;
}

bool TestImageGenerator::cycle() {
    lms::imaging::BGRAImageGraphics g(*m_image);
    g.fillTransparent();
    g.setColor(lms::imaging::red);
    g.drawRect(10, 10, 200, 200);

    return true;
}
