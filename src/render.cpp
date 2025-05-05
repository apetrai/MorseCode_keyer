#include "../include/render.h"

void SetWindow::ResizeWindow(sf::RenderWindow &win, sf::View &view) {
    float aspectRatio = float(win.getSize().x) / float(win.getSize().y);
    view.setSize(VIEW_HEIGHT * aspectRatio, VIEW_HEIGHT);
}