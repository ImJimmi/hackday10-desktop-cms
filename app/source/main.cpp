#include <juce_gui_basics/juce_gui_basics.h>

#include "Window.h"

class App : public juce::JUCEApplication
{
public:
    App() = default;

    const juce::String getApplicationName() final
    {
        return APP_NAME;
    }

    const juce::String getApplicationVersion() final
    {
        return APP_VERSION;
    }

    void initialise(const juce::String& /*args*/) final
    {
        window = std::make_unique<Window>();
        window->onClose = [this]() {
            systemRequestedQuit();
        };
    }

    void shutdown() final
    {
        window = nullptr;
    }

private:
    std::unique_ptr<Window> window;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(App)
};

START_JUCE_APPLICATION(App)
