//
//  Aggregate.h
//  CSE168_Rendering
//
//  Created by Gael Jochaud du Plessix on 4/15/14.
//
//

#ifndef __CSE168_Rendering__Aggregate__
#define __CSE168_Rendering__Aggregate__

#include "Core.h"
#include "Primitive.h"

class Aggregate : public Primitive {
public:
    
    virtual ~Aggregate();
    
    Aggregate& operator<<(Primitive* primitive);
    
    virtual void preprocess();
    virtual void addPrimitive(Primitive* primitive) = 0;
};

#endif /* defined(__CSE168_Rendering__Aggregate__) */