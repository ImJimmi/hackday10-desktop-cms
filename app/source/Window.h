#pragma once

#include <BinaryData.h>
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

        image.setImage(juce::ImageCache::getFromMemory(BinaryData::forest_jpg,
                                                       BinaryData::forest_jpgSize));
        image.setSize(image.getImage().getWidth(),
                      image.getImage().getHeight());

        static constexpr auto resizeWindowToFitContent = true;
        setContentNonOwned(&image, resizeWindowToFitContent);

        centreWithSize(image.getWidth(),
                       image.getHeight());
    }

    void closeButtonPressed() final
    {
        if (onClose != nullptr)
            onClose();
    }

    std::function<void(void)> onClose = nullptr;

private:
    juce::ImageComponent image;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(Window)
};
