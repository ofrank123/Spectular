/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "PluginProcessor.h"

//==============================================================================
/**
*/
class SpectularAudioProcessorEditor : 
    public juce::AudioProcessorEditor,
    public juce::FileDragAndDropTarget
{
public:
    SpectularAudioProcessorEditor (SpectularAudioProcessor&);
    ~SpectularAudioProcessorEditor() override;

    //==============================================================================
    void paint (juce::Graphics&) override;
    void resized() override;
private:
    // This reference is provided as a quick way for your editor to
    // access the processor object that created it.
    SpectularAudioProcessor& audioProcessor;
    juce::AudioFormatManager formatManager;

    bool isInterestedInFileDrag (const juce::StringArray& files) override;
    void filesDropped(const juce::StringArray &files, int x, int y) override;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (SpectularAudioProcessorEditor)
};
