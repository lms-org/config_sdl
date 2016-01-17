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

    int pos = std::abs((cycleCounter() % 1280) - 640);

    switch(config().get<int>("type")) {
    case 1:
        g.setColor(lms::imaging::red);
        g.fillRect(640-pos, 10, 200, 200);
        break;
    case 2:
        g.setColor(lms::imaging::blue);
        g.drawLine(0,0,pos,480);
        break;
    case 3:
        g.setColor(lms::imaging::yellow);
        g.drawRect(100, 100, 60, 60);
        break;
    }

    return true;
}
