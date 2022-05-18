#include <juce_gui_basics/juce_gui_basics.h>

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
        std::cout << "Hello, World!" << std::endl;

        systemRequestedQuit();
    }

    void shutdown() final
    {
        std::cout << "Goodbye, World!" << std::endl;
    }

private:
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(App)
};

START_JUCE_APPLICATION(App)
