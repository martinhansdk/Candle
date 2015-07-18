#ifndef GCODEPARSER_H
#define GCODEPARSER_H

#include <QObject>
#include <QVector3D>
#include "pointsegment.h"
#include "gcodepreprocessorutils.h"

class GcodeParser : public QObject
{
    Q_OBJECT
public:
    explicit GcodeParser(QObject *parent = 0);
    ~GcodeParser();

    bool getConvertArcsToLines();
    void setConvertArcsToLines(bool convertArcsToLines);
    bool getRemoveAllWhitespace();
    void setRemoveAllWhitespace(bool removeAllWhitespace);
    double getSmallArcSegmentLength();
    void setSmallArcSegmentLength(double smallArcSegmentLength);
    double getSmallArcThreshold();
    void setSmallArcThreshold(double smallArcThreshold);
    double getSpeedOverride();
    void setSpeedOverride(double speedOverride);
    int getTruncateDecimalLength();
    void setTruncateDecimalLength(int truncateDecimalLength);
    void reset();
    PointSegment *addCommand(QString command);
    PointSegment *addCommand(QList<QString> args);
    QVector3D* getCurrentPoint();
    QList<PointSegment *> expandArc();
    QList<QString> preprocessCommands(QList<QString> commands);
    QList<QString> preprocessCommand(QString command);
    QList<QString> convertArcsToLines(QString command);
    QList<PointSegment *> getPointSegmentList();
signals:

public slots:

private:

    // Current state
    bool m_isMetric;
    bool m_inAbsoluteMode;
    bool m_inAbsoluteIJKMode;
    QString m_lastGcodeCommand;
    QVector3D m_currentPoint;
    int m_commandNumber;

    // Settings
    double m_speedOverride;
    int m_truncateDecimalLength;
    bool m_removeAllWhitespace;
    bool m_convertArcsToLines;
    double m_smallArcThreshold;
    // Not configurable outside, but maybe it should be.
    double m_smallArcSegmentLength;

    // The gcode.
    QList<PointSegment*> m_points;

    PointSegment *processCommand(QList<QString> args);
    PointSegment *handleGCode(QString code, QList<QString> args);
    PointSegment *addLinearPointSegment(QVector3D nextPoint, bool fastTraverse);
    PointSegment *addArcPointSegment(QVector3D nextPoint, bool clockwise, QList<QString> args);
    void setLastGcodeCommand(QString num);
};

#endif // GCODEPARSER_H