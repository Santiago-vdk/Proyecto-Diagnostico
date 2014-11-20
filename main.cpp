#include <QApplication>
#include <gui.h>
#include <QBuffer>
#include <QAudioOutput>
#include <QDebug>

#include <QSound>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    gui w;
    w.show();

    //    QFile audio_file("C://ACDCHighwayToHell.wav");
    //    if(audio_file.open(QIODevice::ReadOnly)) {
    //        audio_file.seek(44); // skip wav header
    //        QByteArray audio_data = audio_file.readAll();
    //        audio_file.close();

    //        QBuffer* audio_buffer = new QBuffer(&audio_data);
    //        qDebug() << audio_buffer->size();

    //        QAudioFormat format;

    //        format.setSampleSize(16);
    //        format.setSampleRate(44100);
    //        format.setChannelCount(2);
    //        format.setCodec("audio/pcm");
    //        format.setByteOrder(QAudioFormat::LittleEndian);
    //        format.setSampleType(QAudioFormat::UnSignedInt);

    //        QAudioDeviceInfo info(QAudioDeviceInfo::defaultOutputDevice());
    //        if (!info.isFormatSupported(format)) {
    //            qWarning()<<"raw audio format not supported by backend, cannot play audio.";

    //        }
    //        qDebug() << info.deviceName();

    //        QAudioOutput output(info, format);
    //        output.start(audio_buffer);

    //        // ...then wait for the sound to finish
    //        QEventLoop loop;
    //        QObject::connect(&output, SIGNAL(stateChanged(QAudio::State)), &loop, SLOT(quit()));
    //        do {
    //            loop.exec();
    //        } while(output.state() == QAudio::ActiveState);


    //    }
    //    else{
    //        qDebug("False");
    //    }

    return a.exec();
}
