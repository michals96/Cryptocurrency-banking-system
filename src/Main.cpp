#include <Wt/WApplication.h>
#include <Wt/WBreak.h>
#include <Wt/WContainerWidget.h>
#include <Wt/WLineEdit.h>
#include <Wt/WPushButton.h>
#include <Wt/WText.h>
#include "Hello.h"

class HelloApplication : public Wt::WApplication
{
public:
    HelloApplication(const Wt::WEnvironment& env);

private:
    Wt::WLineEdit* nameEdit_;
    Wt::WText* greeting_;
    
    void greet();
};

HelloApplication::HelloApplication(const Wt::WEnvironment& env)
    : WApplication(env)
{
    setTitle("Web banking system");                           
    std::unique_ptr<Wt::WText> title(Wt::cpp14::make_unique<Wt::WText>("<h1>A Witty game: Hangman</h1>"));
    root()->addWidget(std::move(title));
    /* root()->addWidget(Wt::cpp14::make_unique<Wt::WText>("Your name, please ? ")); 

    nameEdit_ = root()->addWidget(Wt::cpp14::make_unique<Wt::WLineEdit>());
    nameEdit_->setFocus();                              

    auto button = root()->addWidget(Wt::cpp14::make_unique<Wt::WPushButton>("Greet me."));
    // create a button
    button->setMargin(25, Wt::Side::Left);                  

    root()->addWidget(Wt::cpp14::make_unique<Wt::WBreak>());   
    greeting_ = root()->addWidget(Wt::cpp14::make_unique<Wt::WText>()); 

    button->clicked().connect(this, &HelloApplication::greet);

    nameEdit_->enterPressed().connect(std::bind(&HelloApplication::greet, this));

    button->clicked().connect([=]() {
        std::cerr << "Hello there, " << nameEdit_->text() << std::endl;
        });

    Wt::WLink link = Wt::WLink("https://www.emweb.be/");
    link.setTarget(Wt::LinkTarget::NewWindow);

    auto button2 = root()->addWidget(Wt::cpp14::make_unique<Wt::WAnchor>(link));

    button2->addNew<Wt::WImage>(Wt::WLink("https://www.emweb.be/css/emweb_small.png"));*/

}

void HelloApplication::greet()
{
    greeting_->setText("Hello there, " + nameEdit_->text());
}

int main(int argc, char** argv)
{
    return Wt::WRun(argc, argv, [](const Wt::WEnvironment& env) {
        return Wt::cpp14::make_unique<HelloApplication>(env);
        });
}