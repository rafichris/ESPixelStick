#ifndef PAGE_DEMO_PIXEL_H_
#define PAGE_DEMO_PIXEL_H_

void send_demo_pixel_html(AsyncWebServerRequest *request) {
    if (request->params()) {
        if (request->hasParam("stopDemo", true)) {
          demo = 0;
        } else {
          for (uint8_t i = 0; i < request->params(); i++) {
            AsyncWebParameter *p = request->getParam(i);
            if (p->name() == "rangeValue1r") { /* ALL */ demoPixelValueR = p->value().toInt();     demo = 1; }
            if (p->name() == "rangeValue1g") { /* ALL */ demoPixelValueG = p->value().toInt();     demo = 1; }
            if (p->name() == "rangeValue1b") { /* ALL */ demoPixelValueB = p->value().toInt();     demo = 1; }
            if (p->name() == "rangeValue2") { /* ON-OFF */ demoPixelValue = p->value().toInt();  demo = 2; }
            if (p->name() == "rangeValue3")   { /* HOPPING */ demoPixelValue = p->value().toInt(); demo = 3; }
            if (p->name() == "rangeValue4")   { /* FLIPPING */ demoPixelValue = p->value().toInt(); demo = 4; }
            if (p->name() == "rangeValue5")   { /* PULSE */ demoPixelValue = p->value().toInt(); demo = 5; }
          }
        }
        AsyncWebServerResponse *response = request->beginResponse(303);
        response->addHeader("Location", request->url());
        request->send(response);
    } else {
        request->send(400);
    }
}

void send_demo_pixel_vals(AsyncWebServerRequest *request) {
    String values = "";
    request->send(200, "text/plain", values);
}

#endif /* PAGE_DEMO_PIXEL_H_ */
