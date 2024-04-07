/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
SpectularAudioProcessorEditor::SpectularAudioProcessorEditor (SpectularAudioProcessor& p)
    : AudioProcessorEditor (&p), audioProcessor (p)
{
    // Make sure that before the constructor has finished, you've set the
    // editor's size to whatever you need it to be.
    setSize (400, 300);

    formatManager.registerBasicFormats();
}

SpectularAudioProcessorEditor::~SpectularAudioProcessorEditor()
{
}

//==============================================================================
void SpectularAudioProcessorEditor::paint (juce::Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    g.fillAll (getLookAndFeel().findColour (juce::ResizableWindow::backgroundColourId));

    g.setColour (juce::Colours::white);
    g.setFont (15.0f);
    g.drawFittedText ("Drop a file to start!", getLocalBounds(), juce::Justification::centred, 1);
}

void SpectularAudioProcessorEditor::resized()
{
    // This is generally where you'll want to lay out the positions of any
    // subcomponents in your editor..
}

//------------------------------
//~ ojf: drag and drop

bool SpectularAudioProcessorEditor::isInterestedInFileDrag(const juce::StringArray &files)
{
    return true;
}

void SpectularAudioProcessorEditor::filesDropped(const juce::StringArray &files, int x, int y)
{
    const juce::String path = files.getReference(0);

    juce::AudioFormatReader *reader = formatManager.createReaderFor(juce::File(path));
    if (reader == nullptr) {
        DBG("File must be a .wav!");
        return;
    }

    f32 *buffer = new f32[reader->lengthInSamples];

    reader->read(&buffer, 1, 0, reader->lengthInSamples);

    delete reader;
}
