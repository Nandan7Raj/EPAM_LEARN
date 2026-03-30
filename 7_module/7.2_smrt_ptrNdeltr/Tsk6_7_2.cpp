//
// Created by NandanRaj on 30-03-2026.
//
#include<iostream>
#include<memory>
#include<string>
#include <utility>
class Texture {
    std::string name;
public:
    Texture(const std::string& name):name(name) {
        std::cout<<"[Texture] Loading: "<<this->name<<std::endl;
    }
    ~Texture() {
        std::cout<<"[Texture] Unloading: " <<this->name<<std::endl;
    }

    void render() const {
        std::cout << "[Texture] Rendering with: " << name << std::endl;
    }
};

class Shader {
    std::string name;
public:
    Shader(const std::string& name):name(name) {
        std::cout<<"[Shader] Compiling: "<<this->name<<std::endl;
    }
    ~Shader() {
        std::cout<<"[Shader] Deleting: " <<this->name<<std::endl;
    }

    void apply() const {
        std::cout << "[Shader] Applying: " << name << std::endl;
    }
};

class GameObject {
    std::unique_ptr<Texture> texturePtr;
    std::shared_ptr<Shader> shaderPtr;
public:
    GameObject(const std::string& textureName, std::shared_ptr<Shader> sharedShader):
    texturePtr(std::make_unique<Texture>(textureName)),shaderPtr(sharedShader) {
        std::cout<<"[GameObject] Created.\n";
    }
    ~GameObject() {
        std::cout<<"[GameObject] Destroyed.\n";
    }
    void draw() const{
        texturePtr->render();//Calls render on the unique Texture
        shaderPtr->apply();// Calls apply on shared Shader
    }
    void changeTexture(const std::string& newTextureName) {
        texturePtr=std::make_unique<Texture>(newTextureName);
    }
};

int main() {
    std::shared_ptr<Shader> defaultLightingShader=std::make_shared<Shader>("BasicLightingShader");
    std::shared_ptr<Shader> postFxShader=std::make_shared<Shader>("GrayscaleFilterShader");

    GameObject player("PlayerTexture",defaultLightingShader);
    GameObject enemy("EnemyTexture",defaultLightingShader);
    GameObject background("BackgroundTexture",postFxShader);

    std::cout << "\n--- Drawing GameObjects ---" << std::endl;
    player.draw();
    enemy.draw();
    background.draw();

    // Changing player's texture
    player.changeTexture("PlayerDamagedTexture");
    player.draw();

    std::cout << "\n--- Demonstrate Scope-based Cleanup ---" << std::endl;
{
    std::cout << "Entering a local scope..." << std::endl;
    GameObject temporaryProp("TempPropTexture", defaultLightingShader); // Creates a GameObject
    temporaryProp.draw();
    std::cout << "Exiting local scope..." << std::endl;
}

}