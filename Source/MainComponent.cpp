#include "MainComponent.h"

//==============================================================================
MainComponent::MainComponent()
{

    setSize (100, 100);


    if (juce::RuntimePermissions::isRequired (juce::RuntimePermissions::recordAudio)
        && ! juce::RuntimePermissions::isGranted (juce::RuntimePermissions::recordAudio))
    {
        juce::RuntimePermissions::request (juce::RuntimePermissions::recordAudio,
                                           [&] (bool granted) { setAudioChannels (granted ? 2 : 0, 2); });
    }
    else
    {
    
        setAudioChannels (2, 2);
    }
}

MainComponent::~MainComponent()
{
    // This shuts down the audio device and clears the audio source.
    shutdownAudio();
}

//==============================================================================
void MainComponent::prepareToPlay (int samplesPerBlockExpected, double sampleRate)
{
    // This function will be called when the audio device is started, or when
    // its settings (i.e. sample rate, block size, etc) are changed.

    // You can use this function to initialise any resources you might need,
    // but be careful - it will be called on the audio thread, not the GUI thread.

    // For more details, see the help for AudioProcessor::prepareToPlay()
}




//this is really import!!!===================================================
void MainComponent::getNextAudioBlock (const juce::AudioSourceChannelInfo& bufferToFill)
{
    //for loop here.
    for(int channel = 0; channel < bufferToFill.buffer->getNumChannels(); ++channel)
    {
        float* const buffer = bufferToFill.buffer->getWritePointer(channel, bufferToFill.startSample);
        //for loop
        for (int sample = 0; sample < bufferToFill.numSamples; ++ sample)
        {
            //this math is extremly importent with out this line it will blow up are speakers please becare!!!
            buffer[sample] = (random.nextFloat() * 2.0f - 1.0f) * 0.25f;
        }
        
        
        
    }
    //this is block all sound from coming out line below
    //bufferToFill.clearActiveBufferRegion();
}
//==============================================================================
void MainComponent::releaseResources()
{
    // This will be called when the audio device stops, or when it is being
    // restarted due to a setting change.

    // For more details, see the help for AudioProcessor::releaseResources()
}

//==============================================================================
void MainComponent::paint (juce::Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    g.fillAll (getLookAndFeel().findColour (juce::ResizableWindow::backgroundColourId));

    // You can add your drawing code here!

}

void MainComponent::resized()
{
    // This is called when the MainContentComponent is resized.
    // If you add any child components, this is where you should
    // update their positions.
}
