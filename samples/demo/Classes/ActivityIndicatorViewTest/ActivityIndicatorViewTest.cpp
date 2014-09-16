#include "ActivityIndicatorViewTest.h"

#define CAColor_blueStyle ccc4(51,204,255,255)

ActivityIndicatorViewTest::ActivityIndicatorViewTest()
{
	CADrawerController* drawer = (CADrawerController*)CAApplication::getApplication()->getRootWindow()->getRootViewController();
	drawer->setTouchMoved(false);
}

ActivityIndicatorViewTest::~ActivityIndicatorViewTest()
{
	CADrawerController* drawer = (CADrawerController*)CAApplication::getApplication()->getRootWindow()->getRootViewController();
	drawer->setTouchMoved(true);
}

void ActivityIndicatorViewTest::viewDidLoad()
{
	size = this->getView()->getBounds().size;
	this->getView()->setColor(ccc4(58,210,129,255));

	whiteLarge = CAActivityIndicatorView::createWithCenter(CADipRect(size.width*0.5, size.height*0.25,
		size.width*0.2, size.width*0.2));
	whiteLarge->setStyle(CAActivityIndicatorViewStyleWhiteLarge);
	this->getView()->addSubview(whiteLarge);
	whiteLarge->startAnimating();

	white = CAActivityIndicatorView::createWithCenter(CADipRect(size.width*0.5, size.height*0.5,
		size.width*0.2,size.width*0.2));
	white->setStyle(CAActivityIndicatorViewStyleWhite);
	this->getView()->addSubview(white);
	white->startAnimating();

	gray = CAActivityIndicatorView::createWithCenter(CADipRect(size.width*0.5, size.height*0.75,
		size.width*0.2, size.width*0.2));
	gray->setStyle(CAActivityIndicatorViewStyleGray);
	this->getView()->addSubview(gray);
	gray->startAnimating();
}

void ActivityIndicatorViewTest::viewDidUnload()
{
	whiteLarge->stopAnimating();
	white->stopAnimating();
	gray->stopAnimating();
	this->getView()->removeAllSubviews();
}

void ActivityIndicatorViewTest::keyBackClicked()
{
	CCLog("------------------");
	whiteLarge->stopAnimating();
	white->stopAnimating();
	gray->stopAnimating();
}