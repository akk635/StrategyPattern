#include <memory>

enum class T_ToolVecSlopeMode {
    Automatic,
    Fix,
    Variable    
};

class T_BarrelTool {
public:    
    double mStartTiltAngle{22.5};
    double mEndTiltAngle{0.};
    double mFixTiltAngle{10.};
};

class T_BarrelToolTilt {
public:    
    T_BarrelToolTilt(T_ToolVecSlopeMode aSlopeMode)
        :mSlopeMode(aSlopeMode){}
    double CalcTiltAngle(double const depthPara)    
    {
        switch(mSlopeMode) {
            case T_ToolVecSlopeMode::Automatic:
                return 0.;
            break;
            case T_ToolVecSlopeMode::Fix:
                return mBarrelTool.mFixTiltAngle; 
            break;
            case T_ToolVecSlopeMode::Variable:
                return (1.0 - depthPara)*mBarrelTool.mStartTiltAngle + depthPara * mBarrelTool.mEndTiltAngle;
            break;
        }
    }

private:
    T_ToolVecSlopeMode mSlopeMode;
    T_BarrelTool       mBarrelTool;
};

int main()
{
    auto ToolTilt = std::make_unique<T_BarrelToolTilt>(T_ToolVecSlopeMode::Fix);

    auto depthPara = 0.5f;
    auto result = ToolTilt->CalcTiltAngle(depthPara);

    return 0;
}