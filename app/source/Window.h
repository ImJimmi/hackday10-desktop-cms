#pragma once

#include <juce_gui_basics/juce_gui_basics.h>

class Window : public juce::DocumentWindow
{
public:
    Window()
        : juce::DocumentWindow{ APP_NAME,
                                juce::Colours::black,
                                juce::DocumentWindow::allButtons }
    {
        setUsingNativeTitleBar(true);
        setResizable(true, false);
        setVisible(true);

        centreWithSize(400, 300);
    }

    void closeButtonPressed() final
    {
        if (onClose != nullptr)
            onClose();
    }

    std::function<void(void)> onClose = nullptr;

private:
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(Window)
};
