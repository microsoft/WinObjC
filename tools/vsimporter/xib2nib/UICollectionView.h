#pragma once
#include "UIView.h"
class UICollectionView :
    public UIView
{
private:

public:
    UICollectionView();
    virtual void InitFromXIB(XIBObject *obj);
    virtual void InitFromStory(XIBObject *obj);
    virtual void ConvertStaticMappings(NIBWriter *writer, XIBObject *obj);

    ObjectConverter *Clone();
};

