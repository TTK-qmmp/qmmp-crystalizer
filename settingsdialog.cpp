#include "settingsdialog.h"
#include "crystalizerplugin.h"

#include <QSettings>
#include <QAbstractButton>

SettingsDialog::SettingsDialog(QWidget *parent)
    : QDialog(parent)
{
    m_ui.setupUi(this);
    setAttribute(Qt::WA_DeleteOnClose);
#ifdef Q_OS_UNIX
    for(QAbstractButton *button : m_ui.buttonBox->buttons())
    {
        button->setFocusPolicy(Qt::NoFocus);
    }
#endif
    m_ui.intensitySlider->setRange(0, 100);

#if QT_VERSION >= QT_VERSION_CHECK(6,0,0)
    QSettings settings;
#else
    QSettings settings(Qmmp::configFile(), QSettings::IniFormat);
#endif
    m_intensity = settings.value("Crystalizer/intensity", DEFAULT_INTENSITY).toUInt();
    m_ui.intensitySlider->setValue(m_intensity);
}

void SettingsDialog::accept()
{
#if QT_VERSION >= QT_VERSION_CHECK(6,0,0)
    QSettings settings;
#else
    QSettings settings(Qmmp::configFile(), QSettings::IniFormat);
#endif
    settings.setValue("Crystalizer/intensity", m_ui.intensitySlider->value());
    QDialog::accept();
}

void SettingsDialog::SettingsDialog::reject()
{
    if(CrystalizerPlugin::instance())
    {
        CrystalizerPlugin::instance()->setIntensity(m_intensity); // restore settings
    }
    QDialog::reject();
}

void SettingsDialog::on_intensitySlider_valueChanged(int value)
{
    m_ui.intensityLabel->setText(QString::number(value * 1.0 / DEFAULT_INTENSITY, 'f', 1));
    if(CrystalizerPlugin::instance())
    {
        CrystalizerPlugin::instance()->setIntensity(value);
    }
}
