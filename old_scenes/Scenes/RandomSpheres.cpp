//
//  RandomSpheres.cpp
//  CSE168_Rendering
//
//  Created by Gael Jochaud du Plessix on 4/23/14.
//
//

#include "Utilities/Main.h"

float RangeRand(float a, float b) {
    return a + ((float)rand()/RAND_MAX)*(b-a);
}

void randomSpheres(Scene* &scene, Camera* &camera, QtFilm* &film) {
    // Create scene
    scene = new Scene(new ListAggregate());
    *scene << new SkyLight(vec3(0.8f, 0.8f, 1.0f));
    
    Texture* spheresTexture = ImageLoading::LoadImage("/Users/gael/Desktop/Courses/CSE_168/models/textures/earth.jpg");
    Texture* planeTexture = ImageLoading::LoadImage("/Users/gael/Desktop/Courses/CSE_168/models/textures/scale_brown.png");
    
    // Materials
    Matte* spheresMaterial = new Matte(spheresTexture);
    Matte* planeMaterial = new Matte(planeTexture);
    //white->setColor(vec3(0.6f));
    
    // Create ground plane
    Plane* groundShape = new Plane();
    GeometricPrimitive* ground = new GeometricPrimitive(groundShape, planeMaterial);
    *scene << ground;
    
    // Create spheres
    for(int i=0; i<20; ++i) {
        Sphere* sphereShape = new Sphere();
        GeometricPrimitive* sphere = new GeometricPrimitive(sphereShape, spheresMaterial);
        float rad = RangeRand(0.25f,0.5f);
        vec3 pos(RangeRand(-5.0f,5.0f), rad, RangeRand(-5.0f,5.0f));
        sphereShape->setRadius(rad);
        sphereShape->setCenter(pos);
        *scene << sphere;
    }
    
    // Create lights
    DirectionalLight* sunlgt = new DirectionalLight();
    sunlgt->setSpectrum(Spectrum(vec3(1.0f, 1.0f, 0.9f)));
    sunlgt->setIntensity(1.0f);
    sunlgt->setDirection(vec3(2.0f, -3.0f, -2.0f));
    *scene << sunlgt;
    
    // Create camera
    PerspectiveCamera* perspectiveCamera = new PerspectiveCamera();
    
    perspectiveCamera->lookAt(vec3(-0.75f,0.25f,5.0f), vec3(0.0f,0.5f,0.0f));
    film = new QtFilm(vec2(800, 600));
    perspectiveCamera->setFilm(film);
    
    perspectiveCamera->setVFov(40.0f);
    perspectiveCamera->setAspect(1.33f);
    
    camera = perspectiveCamera;
}

