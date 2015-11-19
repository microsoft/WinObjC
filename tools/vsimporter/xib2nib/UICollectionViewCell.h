#pragma once
#include "UIView.h"

class UICollectionReusableView :
    public UIView
{
public:
    UICollectionReusableView();
    virtual void Awaken();
    virtual void InitFromXIB(XIBObject *obj);
    virtual void InitFromStory(XIBObject *obj);
    virtual void ConvertStaticMappings(NIBWriter *writer, XIBObject *obj);

    ObjectConverter *Clone();
};

class UICollectionViewCell :
    public UICollectionReusableView
{
private:
    UIView *_contentView;

public:
    UICollectionViewCell();
    virtual void Awaken();
    virtual void InitFromXIB(XIBObject *obj);
    virtual void InitFromStory(XIBObject *obj);
    virtual void ConvertStaticMappings(NIBWriter *writer, XIBObject *obj);

    ObjectConverter *Clone();
};

