#include "options.h"
//#include "sgp4sdp4.h"

#include <qsettings.h>
#include <QDebug>



Options::Options() 
{
    qDebug() << "Initializing options";
}

void Options::Initialize()
{
    qDebug() << "Options::Initialize()";

    QSettings settings( "EUMETCastView.ini", QSettings::IniFormat);
    obslon = settings.value("/observer/longitude", 0.0 ).toDouble();
    obslat = settings.value("/observer/latitude", 0.0 ).toDouble();
    obsalt = settings.value( "/observer/altitude", 0.0 ).toDouble();
    buttonMetop=settings.value("/window/buttonmetop", false ).toBool();
    buttonNoaa=settings.value("/window/buttonnoaa", false ).toBool();
    buttonGAC=settings.value("/window/buttongac", false ).toBool();
    buttonHRP=settings.value("/window/buttonhrp", false ).toBool();
    buttonVIIRSM=settings.value("/window/buttonviirs", false ).toBool();
    buttonVIIRSDNB=settings.value("/window/buttonviirsdnb", false ).toBool();
    buttonOLCIefr=settings.value("/window/buttonolciefr", false ).toBool();
    buttonOLCIerr=settings.value("/window/buttonolcierr", false ).toBool();
    buttonSLSTR=settings.value("/window/buttonslstr", false ).toBool();
    buttonDatahubOLCIefr=settings.value("/window/buttondatahubolciefr", false ).toBool();
    buttonDatahubOLCIerr=settings.value("/window/buttondatahubolcierr", false ).toBool();
    buttonDatahubSLSTR=settings.value("/window/buttondatahubslstr", false ).toBool();

    buttonMetopAhrpt=settings.value("/window/buttonmetopAhrpt", false ).toBool();
    buttonMetopBhrpt=settings.value("/window/buttonmetopBhrpt", false ).toBool();
    buttonNoaa19hrpt=settings.value("/window/buttonnoaa19hrpt", false ).toBool();
    buttonM01hrpt=settings.value("/window/buttonM01hrpt", false ).toBool();
    buttonM02hrpt=settings.value("/window/buttonM02hrpt", false ).toBool();

    buttonRealTime=settings.value("/window/buttonrealtime", true ).toBool();
    buttonPhong=settings.value("/window/buttonphong", false ).toBool();
    buttonShowAllSegments=settings.value("/window/buttonshowallsegments", false ).toBool();
    nbrofvisiblesegments=settings.value("/segments/nbrofvisiblesegments", 10).toInt();
    nbrofhours=settings.value("/segments/nbrofhours", 0).toInt();

    metop_invlist=settings.value("/segments/metop_invlist").value<QStringList>();
    noaa_invlist=settings.value("/segments/noaa_invlist").value<QStringList>();
    gac_invlist=settings.value("/segments/gac_invlist").value<QStringList>();
    hrp_invlist=settings.value("/segments/hrp_invlist").value<QStringList>();

    sattrackinimage=settings.value("/segments/sattrackinimage", false ).toBool();

    tlelist = settings.value("/satellite/tlefiles").value<QStringList>();
    QStringList catnbrlistcop;
    catnbrlistcop = settings.value( "/satellite/catnrs" ).value<QStringList>();

    bool found;
    bool ok;

    for ( QStringList::Iterator itcop = catnbrlistcop.begin(); itcop != catnbrlistcop.end(); ++itcop )
    {
        if( catnbrlist.count() == 0)
            catnbrlist.append(*itcop);
        else
        {
            found = false;
            for ( QStringList::Iterator itc = catnbrlist.begin(); itc != catnbrlist.end(); ++itc )
            {
                if ( (*itcop).toInt( &ok, 10) == (*itc).toInt( &ok, 10 ) )
                {
                    found = true;
                    break;
                }
            }

            if( found == false)
            {
                catnbrlist.append(*itcop);
            }
        }
    }


    segmentdirectorylist = settings.value( "/satellite/segmentdirectories" ).value<QStringList>();
    segmentdirectorylistinc = settings.value( "/satellite/segmentdirectoriesinc" ).value<QStringList>();
    realminutesshown=settings.value("/satellite/minutesshown", 10).toInt();

    channellistmetop=settings.value("/segments/channellistmetop").value<QStringList>();
    channellistnoaa=settings.value("/segments/channellistnoaa").value<QStringList>();
    channellistgac=settings.value("/segments/channellistGAC").value<QStringList>();
    channellisthrp=settings.value("/segments/channellistHRP").value<QStringList>();

    stationlistname=settings.value("/window/stationlistname").value<QStringList>();
    stationlistlon=settings.value("/window/stationlistlon").value<QStringList>();
    stationlistlat=settings.value("/window/stationlistlat").value<QStringList>();
    backgroundimage2D=settings.value("/window/backgroundimage2D", "images/Topography.jpg").value<QString>();
    backgroundimage3D=settings.value("/window/backgroundimage3D", "images/NE2_50M_SR_W_4096.jpg").value<QString>();
    tlesources=settings.value("/satellite/tlesources").value<QStringList>();

    gshhsglobe1=settings.value("/window/gshhsglobe1", "gshhs2_3_4/gshhs_i.b").value<QString>();
    gshhsglobe2=settings.value("/window/gshhsglobe2", "gshhs2_3_4/wdb_borders_i.b").value<QString>();
    gshhsglobe3=settings.value("/window/gshhsglobe3", "gshhs2_3_4/wdb_rivers_i.b").value<QString>();
    gshhsoverlay1=settings.value("/window/gshhsoverlay1", "gshhs2_3_4/gshhs_i.b").value<QString>();
    gshhsoverlay2=settings.value("/window/gshhsoverlay2", "gshhs2_3_4/wdb_borders_i.b").value<QString>();
    gshhsoverlay3=settings.value("/window/gshhsoverlay3", "").value<QString>();

    skyboxup=settings.value("/window/skyboxup", "images/ulukai/corona_up.png").value<QString>();
    skyboxdown=settings.value("/window/skyboxdown", "images/ulukai/corona_dn.png").value<QString>();
    skyboxleft=settings.value("/window/skyboxleft", "images/ulukai/corona_lf.png").value<QString>();
    skyboxright=settings.value("/window/skyboxright", "images/ulukai/corona_rt.png").value<QString>();
    skyboxfront=settings.value("/window/skyboxfront", "images/ulukai/corona_ft.png").value<QString>();
    skyboxback=settings.value("/window/skyboxback", "images/ulukai/corona_bk.png").value<QString>();

    sathorizoncolor=settings.value("/window/sathorizoncolor", "#ffff00").value<QString>();
    sattrackcolor=settings.value("/window/sattrackcolor", "#dcdc00").value<QString>();

    satsegmentcolor=settings.value("/window/satsegmentcolor", "#00aa00").value<QString>();
    satsegmentcolorsel=settings.value("/window/satsegmentcolorsel", "#ff0e42").value<QString>();

    globeoverlaycolor1=settings.value("/window/globeoverlaycolor1", "#afaf47").value<QString>();
    globeoverlaycolor2=settings.value("/window/globeoverlaycolor2", "#898969").value<QString>();
    globeoverlaycolor3=settings.value("/window/globeoverlaycolor3", "#54686d").value<QString>();
    geoimageoverlaycolor1=settings.value("/window/imageoverlaycolor1", "#959559").value<QString>();
    geoimageoverlaycolor2=settings.value("/window/imageoverlaycolor2", "#929274").value<QString>();
    geoimageoverlaycolor3=settings.value("/window/imageoverlaycolor3", "#63696f").value<QString>();
    olciimageoverlaycolor=settings.value("/window/olciimageoverlaycolor", "#afaf47").value<QString>();

    globelonlatcolor=settings.value("/window/globelonlatcolor", "#b9b9b9").value<QString>();
    maplccextentcolor=settings.value("/window/maplccextentcolor", "#152ce7").value<QString>();
    mapgvpextentcolor=settings.value("/window/mapgvpextentcolor", "#dc2cc2").value<QString>();
    projectionoverlaycolor1=settings.value("/window/projectionoverlaycolor1", "#a0a351").value<QString>();
    projectionoverlaycolor2=settings.value("/window/projectionoverlaycolor2", "#7d7b60").value<QString>();
    projectionoverlaycolor3=settings.value("/window/projectionoverlaycolor3", "#75749b").value<QString>();
    projectionoverlaylonlatcolor=settings.value("/window/projectionoverlaylonlatcolor", "#b9b9b9").value<QString>();

    smoothprojectiontype = settings.value("/window/smoothprojectiontype", 0 ).toInt();
    equirectangulardirectory=settings.value("/window/equirectangulardirectory", "").value<QString>();

    gridonprojection = settings.value("/window/gridonprojection", true ).toBool();
    textureOn = settings.value("/window/textureon", true ).toBool();
    stationnameOn = settings.value("/window/stationnameon", false ).toBool();
    lightingOn = settings.value("/window/lightingon", true ).toBool();
    imageontextureOnMet = settings.value("/window/imageontextureonmet", false ).toBool();
    imageontextureOnAVHRR = settings.value("/window/imageontextureonavhrr", true ).toBool();
    imageontextureOnVIIRS = settings.value("/window/imageontextureonviirs", true ).toBool();
    imageontextureOnOLCI = settings.value("/window/imageontextureonolci", true ).toBool();
    imageontextureOnSLSTR = settings.value("/window/imageontextureonslstr", true ).toBool();
    windowvectors = settings.value("/window/windowsvectors", false ).toBool();

    localdirremote = settings.value("/window/localdirremote", "").value<QString>();
    dirremote = settings.value("/window/dirremote", "").value<QString>();
    udpmessages = settings.value("/window/udpmessages", false).toBool();

    gshhsglobe1On = settings.value("/window/gshhsglobe1on", true ).toBool();
    gshhsglobe2On = settings.value("/window/gshhsglobe2on", true ).toBool();
    gshhsglobe3On = settings.value("/window/gshhsglobe3on", false ).toBool();
    graytextureOn = settings.value("/window/graytextureon", false ).toBool();
    ephemsplittersizes = settings.value("/ephemwindow/splitterSizes").toByteArray(); // .value<QByteArray>();

    zoomfactoravhrr = settings.value("/window/zoomfactoravhrr", 100).toInt();
    if( zoomfactoravhrr < 5 || zoomfactoravhrr > 500 )
        zoomfactoravhrr = 100;

    zoomfactormeteosat = settings.value("/window/zoomfactormeteosat", 100).toInt();
    if( zoomfactormeteosat < 5 || zoomfactormeteosat > 500 )
        zoomfactormeteosat = 100;

    zoomfactorprojection = settings.value("/window/zoomfactorprojection", 100).toInt();
    if( zoomfactorprojection < 5 || zoomfactorprojection > 500 )
        zoomfactorprojection = 100;

    zoomfactorviirs = settings.value("/window/zoomfactorviirs", 100).toInt();
    if( zoomfactorviirs < 5 || zoomfactorviirs > 500 )
        zoomfactorviirs = 100;

    zoomfactorolci = settings.value("/window/zoomfactorolci", 100).toInt();
    if( zoomfactorolci < 5 || zoomfactorolci > 500 )
        zoomfactorolci = 100;

    zoomfactorslstr = settings.value("/window/zoomfactorslstr", 100).toInt();
    if( zoomfactorslstr < 5 || zoomfactorslstr > 500 )
        zoomfactorslstr = 100;

    currenttoolbox = settings.value("/parameters/currenttoolbox", 0).toInt();

    currenttabwidget = settings.value("/parameters/currenttabwidget", 0).toInt();
    parallel1 = settings.value("/parameters/parallel1", 20).toInt();
    parallel2 = settings.value("/parameters/parallel2", 60).toInt();
    centralmeridian = settings.value("/parameters/centralmeridian", 0).toInt();
    latitudeoforigin = settings.value("/parameters/latitudeoforigin", 0).toInt();
    mapextentnorth  = settings.value("/parameters/mapextentnorth", 10).toInt();
    mapextentsouth  = settings.value("/parameters/mapextentsouth", -10).toInt();
    mapextentwest  = settings.value("/parameters/mapextentwest", -10).toInt();
    mapextenteast  = settings.value("/parameters/mapextenteast", 10).toInt();

    mapextentlamberton  = settings.value("/parameters/mapextentlamberton", false).toBool();
    mapextentperspectiveon  = settings.value("/parameters/mapextentperspectiveon", false).toBool();
    mapheight = settings.value("/parameters/mapheight", 600).toInt();
    mapwidth = settings.value("/parameters/mapwidth", 800).toInt();

    mapgvplon = settings.value("/parameters/mapgvplon", 0.0).toDouble();
    mapgvplat = settings.value("/parameters/mapgvplat", 0.0).toDouble();
    mapgvpheight = settings.value("/parameters/mapgvpheight", 36000).toInt();
    mapgvpscale = settings.value("/parameters/mapgvpscale", 1.0).toDouble();
    maplccscalex = settings.value("/parameters/maplccscalex", 1.0).toDouble();
    maplccscaley = settings.value("/parameters/maplccscaley", 1.0).toDouble();
    meteosatgamma = settings.value("/parameters/meteosatgamma", 1.0).toDouble();
    mapsglat = settings.value("/parameters/mapsglat", 0.0).toDouble();
    mapsglon = settings.value("/parameters/mapsglon", 0.0).toDouble();
    mapsgscale = settings.value("/parameters/mapsgscale", 1.0).toDouble();
    mapsgpanvert = settings.value("/parameters/mapsgpanvert", 0).toInt();
    mapsgpanhorizon = settings.value("/parameters/mapsgpanhorizon", 0).toInt();
    mapsgradius = settings.value("/parameters/mapsgradius", 45.0).toDouble();

    yawcorrection = settings.value("/parameters/yawcorrection", 0.0).toDouble();

    clahecliplimit = settings.value("/parameters/clahecliplimit", 1.0).toFloat();

    lastinputprojection = settings.value("/window/lastinputprojection", 0 ).toInt();
    lastVIIRSband = settings.value("/window/viirsband", 0 ).toInt();

    dnbsblowerlimit = settings.value("/dnb/dnbsblowerlimit", -250 ).toInt();
    dnbsbupperlimit = settings.value("/dnb/dnbsbupperlimit", -100 ).toInt();
    dnbsbvalue = settings.value("/dnb/dnbsbvalue", -209 ).toInt();
    dnbspbwindowsvalue = settings.value("/dnb/dnbspbwindowsvalue", 3 ).toInt();


    colormapMagma = settings.value("/projection/colormapmagma", false ).toBool();
    colormapInferno = settings.value("/projection/colormapinferno", false ).toBool();
    colormapPlasma = settings.value("/projection/colormapplasma", true ).toBool();
    colormapViridis = settings.value("/projection/colormapviridis", false ).toBool();

    remove_OLCI_dirs = settings.value("/parameters/removeolcidirs", false).toBool();
    remove_SLSTR_dirs = settings.value("/parameters/removeslstrdirs", false).toBool();
    usesaturationmask = settings.value("/parameters/usesaturationmask", true).toBool();

    checkStringListValues();
    fbo_changed = false;
    texture_changed = false;
    gridonolciimage = false;

    esauser = settings.value("/datahub/esauser", "").value<QString>();
    esapassword = settings.value("/datahub/esapassword", "").value<QString>();
    eumetsatuser = settings.value("/datahub/eumetsatuser", "").value<QString>();
    eumetsatpassword = settings.value("/datahub/eumetsatpassword", "").value<QString>();
    productdirectory = settings.value("/datahub/productdirectory", "").value<QString>();
    provideresaoreumetsat = settings.value("/datahub/provideresaoreumetsat", false).toBool();
    downloadxmlolciefr = settings.value("/datahub/downloadxmlolciefr", false).toBool();
    downloadxmlolcierr = settings.value("/datahub/downloadxmlolcierr", false).toBool();
    downloadxmlslstr = settings.value("/datahub/downloadxmlslstr", true).toBool();
    xmllogging = false;

    CreateGeoSatelliteIni();

}

void Options::checkStringListValues()
{
    if(channellistmetop.count() != 5) { channellistmetop << "3" << "2" << "1" << "0" << "0"; }
    if(channellistnoaa.count() != 5) { channellistnoaa << "3" << "2" << "1" << "0" << "0"; }
    if(channellistgac.count() != 5) { channellistgac << "3" << "2" << "1" << "0" << "0"; }
    if(channellisthrp.count() != 5) { channellisthrp << "3" << "2" << "1" << "0" << "0"; }

    if(metop_invlist.count() != 5) { metop_invlist << "0" << "0" << "0" << "0" <<"0"; }
    if(noaa_invlist.count() != 5) { noaa_invlist << "0" << "0" << "0" << "0" <<"0"; }
    if(gac_invlist.count() != 5) { gac_invlist << "0" << "0" << "0" << "0" <<"0"; }
    if(hrp_invlist.count() != 5) { hrp_invlist << "0" << "0" << "0" << "0" <<"0"; }

    if(stationlistname.count() == 0)
    {
        stationlistname << "McMurdo Station" << "Maspalomas" << "Svalbard" << "Edmonton" << "Gander" << "Gilmore Creek" <<
                           "Monterey" << "Kangerlussuaq" << "Lannion" << "Saint-Denis (La Reunion)" <<
                           "Moscow" << "Muscat" << "Tromso" << "Ewa Beach" << "Miami" << "Pine Island Glacier" << "Athens";
        stationlistlon << "166.666" << "-15.63" << "15.23" << "-113.5" << "-54.57" << "-147.40" << "-121.55" << "-50.67" <<
                           "-3.5" << "55.50" << "37.569" << "58.29" << "18.933" << "-158.07" << "-80.16" << "-100.0" << "23.769";
        stationlistlat << "-77.85" << "27.78" << "78.13" << "53.33" << "48.95" << "64.97" << "36.35" << "66.98" << "48.75" <<
                          "-20.91" << "55.759" << "23.59" << "69.65" << "21.33" << "25.74" << "-75.166667" << "37.815";
    }


    if(tlesources.count() == 0)
    {
        tlesources << "http://celestrak.com/NORAD/elements/weather.txt";
    }



}

void Options::Save()
{

    qDebug() << QString("Saving Options ");

    QSettings settings( "EUMETCastView.ini", QSettings::IniFormat);

    settings.setValue("/satellite/tlefiles", tlelist );

    QStringList catnbrlistcop;
    bool found;
    bool ok;

    catnbrlistcop = catnbrlist;
    catnbrlist.clear();

    for ( QStringList::Iterator itcop = catnbrlistcop.begin(); itcop != catnbrlistcop.end(); ++itcop )
    {
        if( catnbrlist.count() == 0)
            catnbrlist.append(*itcop);
        else
        {
            found = false;
            for ( QStringList::Iterator itc = catnbrlist.begin(); itc != catnbrlist.end(); ++itc )
            {
                if ( (*itcop).toInt( &ok, 10) == (*itc).toInt( &ok, 10 ) )
                {
                    found = true;
                    break;
                }
            }

            if( found == false)
            {
                catnbrlist.append(*itcop);
            }
        }
    }

    settings.setValue("/satellite/catnrs", catnbrlist );
    settings.setValue("/satellite/segmentdirectories", segmentdirectorylist );
    settings.setValue("/satellite/segmentdirectoriesinc", segmentdirectorylistinc );
    settings.setValue("/satellite/minutesshown", realminutesshown );
    settings.setValue("/segments/nbrofvisiblesegments", nbrofvisiblesegments);
    settings.setValue("/segments/nbrofhours", nbrofhours);
    settings.setValue( "/window/buttonmetop", buttonMetop );
    settings.setValue( "/window/buttonnoaa", buttonNoaa );
    settings.setValue( "/window/buttongac", buttonGAC );
    settings.setValue( "/window/buttonhrp", buttonHRP );
    settings.setValue( "/window/buttonviirs", buttonVIIRSM );
    settings.setValue( "/window/buttonviirsdnb", buttonVIIRSDNB );
    settings.setValue( "/window/buttonolciefr", buttonOLCIefr );
    settings.setValue( "/window/buttonolcierr", buttonOLCIerr );
    settings.setValue( "/window/buttonslstr", buttonSLSTR );
    settings.setValue( "/window/buttondatahubolciefr", buttonDatahubOLCIefr );
    settings.setValue( "/window/buttondatahubolcierr", buttonDatahubOLCIerr );
    settings.setValue( "/window/buttondatahubslstr", buttonDatahubSLSTR );
    settings.setValue( "/window/buttonmetopAhrpt", buttonMetopAhrpt );
    settings.setValue( "/window/buttonmetopBhrpt", buttonMetopBhrpt );
    settings.setValue( "/window/buttonnoaa19hrpt", buttonNoaa19hrpt );
    settings.setValue( "/window/buttonM01hrpt", buttonM01hrpt );
    settings.setValue( "/window/buttonM02hrpt", buttonM02hrpt );

    settings.setValue( "/window/buttonrealtime", buttonRealTime );
    settings.setValue( "/window/buttonphong", buttonPhong );
    settings.setValue( "/window/buttonshowallsegments", buttonShowAllSegments );

    settings.setValue( "/observer/longitude", obslon );
    settings.setValue( "/observer/latitude", obslat );
    settings.setValue( "/observer/altitude", obsalt );

    settings.setValue("/segments/metop_invlist", metop_invlist);
    settings.setValue("/segments/noaa_invlist", noaa_invlist);
    settings.setValue("/segments/gac_invlist", gac_invlist);
    settings.setValue("/segments/hrp_invlist", hrp_invlist);

    settings.setValue( "/segments/sattrackinimage", sattrackinimage );

    settings.setValue("/segments/channellistmetop", channellistmetop);
    settings.setValue("/segments/channellistnoaa", channellistnoaa);
    settings.setValue("/segments/channellistGAC", channellistgac);
    settings.setValue("/segments/channellistHRP", channellisthrp);

    settings.setValue("/window/stationlistname", stationlistname );
    settings.setValue("/window/stationlistlon", stationlistlon );
    settings.setValue("/window/stationlistlat", stationlistlat );

    settings.setValue("/window/backgroundimage2D", backgroundimage2D );
    settings.setValue("/window/backgroundimage3D", backgroundimage3D );
    settings.setValue("/satellite/tlesources", tlesources );

    settings.setValue("/window/gshhsglobe1", gshhsglobe1 );
    settings.setValue("/window/gshhsglobe2", gshhsglobe2 );
    settings.setValue("/window/gshhsglobe3", gshhsglobe3 );
    settings.setValue("/window/gshhsoverlay1", gshhsoverlay1 );
    settings.setValue("/window/gshhsoverlay2", gshhsoverlay2 );
    settings.setValue("/window/gshhsoverlay3", gshhsoverlay3 );

    settings.setValue("/window/skyboxup", skyboxup );
    settings.setValue("/window/skyboxdown", skyboxdown );
    settings.setValue("/window/skyboxleft", skyboxleft );
    settings.setValue("/window/skyboxright", skyboxright );
    settings.setValue("/window/skyboxfront", skyboxfront );
    settings.setValue("/window/skyboxback", skyboxback );

    settings.setValue("/window/sathorizoncolor", sathorizoncolor );
    settings.setValue("/window/sattrackcolor", sattrackcolor );

    settings.setValue("/window/satsegmentcolor", satsegmentcolor );
    settings.setValue("/window/satsegmentcolorsel", satsegmentcolorsel );

    settings.setValue("/window/globeoverlaycolor1", globeoverlaycolor1 );
    settings.setValue("/window/globeoverlaycolor2", globeoverlaycolor2 );
    settings.setValue("/window/globeoverlaycolor3", globeoverlaycolor3 );
    settings.setValue("/window/imageoverlaycolor1", geoimageoverlaycolor1 );
    settings.setValue("/window/imageoverlaycolor2", geoimageoverlaycolor2 );
    settings.setValue("/window/imageoverlaycolor3", geoimageoverlaycolor3 );
    settings.setValue("/window/olciimageoverlaycolor", olciimageoverlaycolor );

    settings.setValue("/window/globelonlatcolor", globelonlatcolor );
    settings.setValue("/window/maplccextentcolor", maplccextentcolor );
    settings.setValue("/window/mapgvpextentcolor", mapgvpextentcolor );
    settings.setValue("/window/projectionoverlaycolor1", projectionoverlaycolor1 );
    settings.setValue("/window/projectionoverlaycolor2", projectionoverlaycolor2 );
    settings.setValue("/window/projectionoverlaycolor3", projectionoverlaycolor3 );
    settings.setValue("/window/projectionoverlaylonlatcolor", projectionoverlaylonlatcolor );

    settings.setValue("/window/smoothprojectiontype", smoothprojectiontype );
    settings.setValue("/window/equirectangulardirectory", equirectangulardirectory );

    settings.setValue("/window/gridonprojection", gridonprojection );
    settings.setValue("/window/textureon", textureOn );
    settings.setValue("/window/stationnameon", stationnameOn );
    settings.setValue("/window/lightingon", lightingOn );
    settings.setValue("/window/imageontextureonmet", imageontextureOnMet );
    settings.setValue("/window/imageontextureonavhrr", imageontextureOnAVHRR );
    settings.setValue("/window/imageontextureonviirs", imageontextureOnVIIRS );
    settings.setValue("/window/imageontextureonolci", imageontextureOnOLCI );
    settings.setValue("/window/imageontextureonslstr", imageontextureOnSLSTR );
    settings.setValue("/window/windowsvectors", windowvectors );

    settings.setValue("/window/gshhsglobe1on", gshhsglobe1On );
    settings.setValue("/window/gshhsglobe2on", gshhsglobe2On );
    settings.setValue("/window/gshhsglobe3on", gshhsglobe3On );
    settings.setValue("/window/graytextureon", graytextureOn );

    settings.setValue("/window/localdirremote", localdirremote );
    settings.setValue("/window/dirremote", dirremote );
    settings.setValue("/window/udpmessages", udpmessages );


    settings.setValue("/ephemwindow/splitterSizes", ephemsplittersizes );

    settings.setValue("/window/zoomfactoravhrr", zoomfactoravhrr );
    settings.setValue("/window/zoomfactormeteosat", zoomfactormeteosat );
    settings.setValue("/window/zoomfactorprojection", zoomfactorprojection );
    settings.setValue("/window/zoomfactorviirs", zoomfactorviirs );
    settings.setValue("/window/zoomfactorolci", zoomfactorolci );
    settings.setValue("/window/zoomfactorslstr", zoomfactorslstr );


    settings.setValue("/parameters/currenttoolbox", currenttoolbox);
    settings.setValue("/parameters/currenttabwidget", currenttabwidget);
    settings.setValue("/parameters/parallel1", parallel1);
    settings.setValue("/parameters/parallel2", parallel2);
    settings.setValue("/parameters/centralmeridian", centralmeridian);
    settings.setValue("/parameters/latitudeoforigin", latitudeoforigin);

    settings.setValue("/parameters/mapextentnorth", mapextentnorth);

    settings.setValue("/dnb/dnbsblowerlimit", dnbsblowerlimit );
    settings.setValue("/dnb/dnbsbupperlimit", dnbsbupperlimit );
    settings.setValue("/dnb/dnbsbvalue", dnbsbvalue );
    settings.setValue("/dnb/dnbspbwindowsvalue", dnbspbwindowsvalue );

    qDebug() << QString("save Options::mapextentnorth = %1").arg(mapextentnorth);
    qDebug() << QString("save Options::mapextentsouth = %1").arg(mapextentsouth);
    qDebug() << QString("save Options::mapextentwest = %1").arg(mapextentwest);
    qDebug() << QString("save Options::mapextenteast = %1").arg(mapextenteast);


    settings.setValue("/parameters/mapextentsouth", mapextentsouth);
    settings.setValue("/parameters/mapextentwest", mapextentwest);
    settings.setValue("/parameters/mapextenteast", mapextenteast);
    settings.setValue("/parameters/mapextentlamberton", mapextentlamberton);
    settings.setValue("/parameters/mapextentperspectiveon", mapextentperspectiveon);
    settings.setValue("/parameters/mapheight", mapheight);
    settings.setValue("/parameters/mapwidth", mapwidth);
    settings.setValue("/parameters/mapgvplon", mapgvplon);
    settings.setValue("/parameters/mapgvplat", mapgvplat);
    settings.setValue("/parameters/mapgvpheight", mapgvpheight);
    settings.setValue("/parameters/mapgvpscale", mapgvpscale);
    settings.setValue("/parameters/maplccscalex", maplccscalex);
    settings.setValue("/parameters/maplccscaley", maplccscaley);
    settings.setValue("/parameters/meteosatgamma", meteosatgamma);
    settings.setValue("/parameters/mapsglat", mapsglat);
    settings.setValue("/parameters/mapsglon", mapsglon);
    settings.setValue("/parameters/mapsgscale", mapsgscale);
    settings.setValue("/parameters/mapsgpanvert", mapsgpanvert);
    settings.setValue("/parameters/mapsgpanhorizon", mapsgpanhorizon);
    settings.setValue("/parameters/mapsgradius", mapsgradius);

    settings.setValue("/parameters/yawcorrection", yawcorrection);
    settings.setValue("/parameters/clahecliplimit", clahecliplimit);

    settings.setValue( "/window/lastinputprojection", lastinputprojection );
    settings.setValue( "/window/viirsband", lastVIIRSband);

    settings.setValue( "/projection/colormapmagma", colormapMagma);
    settings.setValue( "/projection/colormapinferno", colormapInferno);
    settings.setValue( "/projection/colormapplasma", colormapPlasma);
    settings.setValue( "/projection/colormapviridis", colormapViridis);

    settings.setValue("/parameters/removeolcidirs", remove_OLCI_dirs);
    settings.setValue("/parameters/removeslstrdirs", remove_SLSTR_dirs);
    settings.setValue("/parameters/usesaturationmask", usesaturationmask);

    settings.setValue("/datahub/esauser", esauser);
    settings.setValue("/datahub/esapassword", esapassword);
    settings.setValue("/datahub/eumetsatuser", eumetsatuser);
    settings.setValue("/datahub/eumetsatpassword", eumetsatpassword);
    settings.setValue("/datahub/productdirectory", productdirectory);
    settings.setValue("/datahub/provideresaoreumetsat", provideresaoreumetsat);

    settings.setValue("/datahub/downloadxmlolciefr", downloadxmlolciefr);
    settings.setValue("/datahub/downloadxmlolcierr", downloadxmlolcierr);
    settings.setValue("/datahub/downloadxmlslstr", downloadxmlslstr);
}

void Options::CreateGeoSatelliteIni()
{

    QSettings settingsgeo( "GeoSatellites.ini", QSettings::IniFormat);

    GeoSatellites sat;
    for(int i = 0; i < 10; i++)
        geosatellites.append(sat);

    //Data Channel 15
    geosatellites[0].fullname = "Meteosat-11";
    geosatellites[0].shortname = "MET_11";
    geosatellites[0].longitude = 0.0;
    geosatellites[0].longitudelimit1 = -30.0;
    geosatellites[0].longitudelimit2 = 20.0;
    geosatellites[0].protocol = "XRIT";
    geosatellites[0].rss = false;
    geosatellites[0].searchstring = "H-000-MSG4__-MSG4_PAR____";
    geosatellites[0].indexsearchstring = 0;
    geosatellites[0].filepattern = "H-???-??????-?????????___-?????????-0?????___-%1-C_";
    geosatellites[0].imagewidth = 3712;
    geosatellites[0].imageheight = 3712;
    geosatellites[0].imagewidthhrv0 = 5568;
    geosatellites[0].imageheighthrv0 = 2320;
    geosatellites[0].imagewidthhrv1 = 5568;
    geosatellites[0].imageheighthrv1 = 11136;
    geosatellites[0].indexspectrum = 26;
    geosatellites[0].indexfilenbr = 36;
    geosatellites[0].lengthfilenbr = 6;
    geosatellites[0].indexdate = 46;
    geosatellites[0].lengthdate = 12;

    geosatellites[0].spectrumhrv = "HRV";
    geosatellites[0].spectrumvaluehrv = "HRV";
    geosatellites[0].indexspectrumhrv = 26;
    geosatellites[0].indexfilenbrhrv = 36;
    geosatellites[0].lengthfilenbrhrv = 6;
    geosatellites[0].indexdatehrv = 46;
    geosatellites[0].lengthdatehrv = 12;

    geosatellites[0].color = true;
    geosatellites[0].maxsegments = 8;
    geosatellites[0].maxsegmentshrv = 24;
    geosatellites[0].startsegmentnbrtype0 = 5;
    geosatellites[0].startsegmentnbrhrvtype0 = 19;
    geosatellites[0].startsegmentnbrtype1 = 1;
    geosatellites[0].startsegmentnbrhrvtype1 = 1;
    geosatellites[0].prologfile = true;
    geosatellites[0].epilogfile = true;


    //Data Channel 2
    geosatellites[1].fullname = "Meteosat-10";
    geosatellites[1].shortname = "MET_10";
    geosatellites[1].longitude = 0.0;
    geosatellites[1].longitudelimit1 = -30.0;
    geosatellites[1].longitudelimit2 = 20.0;
    geosatellites[1].protocol = "XRIT";
    geosatellites[1].rss = false;
    geosatellites[1].searchstring = "H-000-MSG3__-MSG3________";
    geosatellites[1].indexsearchstring = 0;
    geosatellites[1].filepattern = "H-???-??????-?????????___-?????????-0?????___-%1-C_";
    geosatellites[1].imagewidth = 3712;
    geosatellites[1].imageheight = 3712;
    geosatellites[1].imagewidthhrv0 = 5568;
    geosatellites[1].imageheighthrv0 = 2320;
    geosatellites[1].imagewidthhrv1 = 5568;
    geosatellites[1].imageheighthrv1 = 11136;
    geosatellites[1].indexspectrum = 26;
    geosatellites[1].indexfilenbr = 36;
    geosatellites[1].lengthfilenbr = 6;
    geosatellites[1].indexdate = 46;
    geosatellites[1].lengthdate = 12;

    geosatellites[1].spectrumhrv = "HRV";
    geosatellites[1].spectrumvaluehrv = "HRV";
    geosatellites[1].indexspectrumhrv = 26;
    geosatellites[1].indexfilenbrhrv = 36;
    geosatellites[1].lengthfilenbrhrv = 6;
    geosatellites[1].indexdatehrv = 46;
    geosatellites[1].lengthdatehrv = 12;

    geosatellites[1].color = true;
    geosatellites[1].maxsegments = 8;
    geosatellites[1].maxsegmentshrv = 24;
    geosatellites[1].startsegmentnbrtype0 = 5;
    geosatellites[1].startsegmentnbrhrvtype0 = 19;
    geosatellites[1].startsegmentnbrtype1 = 1;
    geosatellites[1].startsegmentnbrhrvtype1 = 1;
    geosatellites[1].prologfile = true;
    geosatellites[1].epilogfile = true;


    //Data Channel 5
    geosatellites[2].fullname = "Meteosat-9";
    geosatellites[2].shortname = "MET_9";
    geosatellites[2].longitude = 9.5;
    geosatellites[2].longitudelimit1 = 0.0;
    geosatellites[2].longitudelimit2 = 0.0;
    geosatellites[2].protocol = "XRIT";
    geosatellites[2].rss = true;
    geosatellites[2].searchstring = "H-000-MSG2__-MSG2_RSS____";
    geosatellites[2].indexsearchstring = 0;
    geosatellites[2].filepattern = "H-???-??????-?????????___-?????????-0?????___-%1-C_";
    geosatellites[2].imagewidth = 3712;
    geosatellites[2].imageheight = 1392;
    geosatellites[2].imagewidthhrv0 = 5568;
    geosatellites[2].imageheighthrv0 = 2320;
    geosatellites[2].imagewidthhrv1 = 0;
    geosatellites[2].imageheighthrv1 = 0;

    geosatellites[2].indexspectrum = 26;
    geosatellites[2].indexfilenbr = 36;
    geosatellites[2].lengthfilenbr = 6;
    geosatellites[2].indexdate = 46;
    geosatellites[2].lengthdate = 12;

    geosatellites[2].spectrumhrv = "HRV";
    geosatellites[2].spectrumvaluehrv = "HRV";
    geosatellites[2].indexspectrumhrv = 26;
    geosatellites[2].indexfilenbrhrv = 36;
    geosatellites[2].lengthfilenbrhrv = 6;
    geosatellites[2].indexdatehrv = 46;
    geosatellites[2].lengthdatehrv = 12;

    geosatellites[2].color = true;
    geosatellites[2].maxsegments = 8;
    geosatellites[2].maxsegmentshrv = 24;
    geosatellites[2].startsegmentnbrtype0 = 6;
    geosatellites[2].startsegmentnbrhrvtype0 = 19;
    geosatellites[2].startsegmentnbrtype1 = 0;
    geosatellites[2].startsegmentnbrhrvtype1 = 0;
    geosatellites[2].prologfile = true;
    geosatellites[2].epilogfile = true;


    //E1B-GEO-1
    geosatellites[3].fullname = "Meteosat-8";
    geosatellites[3].shortname = "MET_8";
    geosatellites[3].longitude = 41.5;
    geosatellites[3].longitudelimit1 = 20.0;
    geosatellites[3].longitudelimit2 = 92.0;
    geosatellites[3].protocol = "XRIT";
    geosatellites[3].rss = false;
    geosatellites[3].searchstring = "H-000-MSG1__-MSG1_IODC___";
    geosatellites[3].indexsearchstring = 0;
    geosatellites[3].filepattern = "H-???-??????-?????????___-?????????-0?????___-%1-C_";
    geosatellites[3].imagewidth = 3712;
    geosatellites[3].imageheight = 3712;
    geosatellites[3].imagewidthhrv0 = 5568;
    geosatellites[3].imageheighthrv0 = 2320;
    geosatellites[3].imagewidthhrv1 = 5568;
    geosatellites[3].imageheighthrv1 = 11136;

    geosatellites[3].indexspectrum = 26;
    geosatellites[3].indexfilenbr = 36;
    geosatellites[3].lengthfilenbr = 6;
    geosatellites[3].indexdate = 46;
    geosatellites[3].lengthdate = 12;

    geosatellites[3].spectrumhrv = "HRV";
    geosatellites[3].spectrumvaluehrv = "HRV";
    geosatellites[3].indexspectrumhrv = 26;
    geosatellites[3].indexfilenbrhrv = 36;
    geosatellites[3].lengthfilenbrhrv = 6;
    geosatellites[3].indexdatehrv = 46;
    geosatellites[3].lengthdatehrv = 12;

    geosatellites[3].color = true;
    geosatellites[3].maxsegments = 8;
    geosatellites[3].maxsegmentshrv = 24;
    geosatellites[3].startsegmentnbrtype0 = 5;
    geosatellites[3].startsegmentnbrhrvtype0 = 19;
    geosatellites[3].startsegmentnbrtype1 = 1;
    geosatellites[3].startsegmentnbrhrvtype1 = 1;
    geosatellites[3].prologfile = true;
    geosatellites[3].epilogfile = true;



    for(int i = 0; i < 4; i++)
    {
        geosatellites[i].spectrumlist << "VIS006" << "VIS008" << "IR_016" << "IR_039" << "WV_062" << "WV_073" << "IR_087" << "IR_097" << "IR_108" << "IR_120" << "IR_134";
        geosatellites[i].spectrumvalueslist << "0.635" << "0.81" << "1.64" << "3.90" << "6.25" << "7.35" << "8.70" << "9.66" << "10.80" << "12.00" << "13.40";
        geosatellites[i].coff = 1856;
        geosatellites[i].loff = 1856;
        geosatellites[i].cfac = 781648343.;
        geosatellites[i].lfac = 781648343.;
        geosatellites[i].coffhrv = 5566;
        geosatellites[i].loffhrv = 5566;
        geosatellites[i].cfachrv = 2344945030.;
        geosatellites[i].lfachrv = 2344945030.;
    }

    //E1B-TPG-1
    geosatellites[4].fullname = "Electro L2";
    geosatellites[4].shortname = "GOMS2";
    geosatellites[4].longitude = 76.1;
    geosatellites[4].longitudelimit1 = 0.0;
    geosatellites[4].longitudelimit2 = 0.0;
    geosatellites[4].protocol = "XRIT";
    geosatellites[4].rss = false;
    geosatellites[4].searchstring = "H-000-GOMS2_-GOMS2_4_____";
    geosatellites[4].indexsearchstring = 0;
    geosatellites[4].filepattern = "H-???-??????-?????????___-?????????-0?????___-%1-C_";
    geosatellites[4].imagewidth = 2784;
    geosatellites[4].imageheight = 2784;
    geosatellites[4].imagewidthhrv0 = 0;
    geosatellites[4].imageheighthrv0 = 0;
    geosatellites[4].imagewidthhrv1 = 0;
    geosatellites[4].imageheighthrv1 = 0;

    geosatellites[4].indexspectrum = 26;
    geosatellites[4].indexfilenbr = 36;
    geosatellites[4].lengthfilenbr = 6;
    geosatellites[4].indexdate = 46;
    geosatellites[4].lengthdate = 12;

    geosatellites[4].spectrumhrv = "";
    geosatellites[4].spectrumvaluehrv = "";
    geosatellites[4].indexspectrumhrv = 0;
    geosatellites[4].indexfilenbrhrv = 0;
    geosatellites[4].lengthfilenbrhrv = 0;
    geosatellites[4].indexdatehrv = 0;
    geosatellites[4].lengthdatehrv = 0;

    geosatellites[4].color = false;
    geosatellites[4].maxsegments = 6;
    geosatellites[4].maxsegmentshrv = 0;
    geosatellites[4].startsegmentnbrtype0 = 0;
    geosatellites[4].startsegmentnbrhrvtype0 = 0;
    geosatellites[4].startsegmentnbrtype1 = 0;
    geosatellites[4].startsegmentnbrhrvtype1 = 0;
    geosatellites[4].prologfile = true;
    geosatellites[4].epilogfile = true;
    geosatellites[4].coff = 1392;
    geosatellites[4].loff = 1392;
    geosatellites[4].cfac = 586236263.;
    geosatellites[4].lfac = 586236263.;
    geosatellites[4].coffhrv = 0;
    geosatellites[4].loffhrv = 0;
    geosatellites[4].cfachrv = 0.;
    geosatellites[4].lfachrv = 0.;



    geosatellites[4].spectrumlist << "00_9_0" << "03_8_0" << "08_0_0" << "09_7_0" << "10_7_0" << "11_9_0";
    geosatellites[4].spectrumvalueslist << "VIS 0.9" << "IR 3.8" << "IR 8.0" << "IR 9.7" << "IR 10.7" << "IR 11.9";

    //Data Channel 12
    geosatellites[5].fullname = "FengYun 2E";
    geosatellites[5].shortname = "FY2E";
    geosatellites[5].longitude = 86.5;
    geosatellites[5].longitudelimit1 = 0.0;
    geosatellites[5].longitudelimit2 = 0.0;
    geosatellites[5].protocol = "HDF";
    geosatellites[5].rss = false;
    geosatellites[5].searchstring = "FY2E_FDI";
    geosatellites[5].indexsearchstring = 31;
    geosatellites[5].imagewidth = 2288;
    geosatellites[5].imageheight = 2288;
    geosatellites[5].imagewidthhrv0 = 9152;
    geosatellites[5].imageheighthrv0 = 9152;
    geosatellites[5].imagewidthhrv1 = 0;
    geosatellites[5].imageheighthrv1 = 0;

    geosatellites[5].indexspectrum = 40;
    geosatellites[5].indexfilenbr = 44;
    geosatellites[5].lengthfilenbr = 3;
    geosatellites[5].indexdate = 14;
    geosatellites[5].lengthdate = 12;

    geosatellites[5].spectrumhrv = "VIS1KM";
    geosatellites[5].spectrumvaluehrv = "HRV";
    geosatellites[5].indexspectrumhrv = 40;
    geosatellites[5].indexfilenbrhrv = 47;
    geosatellites[5].lengthfilenbrhrv = 3;
    geosatellites[5].indexdatehrv = 14;
    geosatellites[5].lengthdatehrv = 12;

    geosatellites[5].color = false;
    geosatellites[5].maxsegments = 1;
    geosatellites[5].maxsegmentshrv = 1;
    geosatellites[5].startsegmentnbrtype0 = 0;
    geosatellites[5].startsegmentnbrhrvtype0 = 0;
    geosatellites[5].startsegmentnbrtype1 = 0;
    geosatellites[5].startsegmentnbrhrvtype1 = 0;
    geosatellites[5].prologfile = false;
    geosatellites[5].epilogfile = false;
    geosatellites[5].coff = 1144;
    geosatellites[5].loff = 1144;
    geosatellites[5].cfac = 468000000.;
    geosatellites[5].lfac = 468000000.;
    geosatellites[5].coffhrv = 4576;
    geosatellites[5].loffhrv = 4576;
    geosatellites[5].cfachrv = 1872000000.;
    geosatellites[5].lfachrv = 1872000000.;



    geosatellites[5].spectrumlist << "VIS" << "IR4" << "IR3" << "IR1" << "IR2";
    geosatellites[5].spectrumvalueslist << "VIS 0.7" << "IR 3.7" << "IR 6.9" << "IR 10.8" << "IR 12.0";

    //Data Channel 12
    geosatellites[6].fullname = "FengYun 2G";
    geosatellites[6].shortname = "FY2G";
    geosatellites[6].longitude = 104.5;
    geosatellites[6].longitudelimit1 = 0.0;
    geosatellites[6].longitudelimit2 = 0.0;
    geosatellites[6].protocol = "HDF";
    geosatellites[6].rss = false;
    geosatellites[6].searchstring = "FY2G_FDI";
    geosatellites[6].indexsearchstring = 31;
    geosatellites[6].imagewidth = 2288;
    geosatellites[6].imageheight = 2288;
    geosatellites[6].imagewidthhrv0 = 9152;
    geosatellites[6].imageheighthrv0 = 9152;
    geosatellites[6].imagewidthhrv1 = 0;
    geosatellites[6].imageheighthrv1 = 0;

    geosatellites[6].indexspectrum = 40;
    geosatellites[6].indexfilenbr = 44;
    geosatellites[6].lengthfilenbr = 3;
    geosatellites[6].indexdate = 14;
    geosatellites[6].lengthdate = 12;

    geosatellites[6].spectrumhrv = "VIS1KM";
    geosatellites[6].spectrumvaluehrv = "HRV";
    geosatellites[6].indexspectrumhrv = 40;
    geosatellites[6].indexfilenbrhrv = 47;
    geosatellites[6].lengthfilenbrhrv = 3;
    geosatellites[6].indexdatehrv = 14;
    geosatellites[6].lengthdatehrv = 12;

    geosatellites[6].color = false;
    geosatellites[6].maxsegments = 1;
    geosatellites[6].maxsegmentshrv = 1;
    geosatellites[6].startsegmentnbrtype0 = 0;
    geosatellites[6].startsegmentnbrhrvtype0 = 0;
    geosatellites[6].startsegmentnbrtype1 = 0;
    geosatellites[6].startsegmentnbrhrvtype1 = 0;
    geosatellites[6].prologfile = false;
    geosatellites[6].epilogfile = false;
    geosatellites[6].coff = 1144;
    geosatellites[6].loff = 1144;
    geosatellites[6].cfac = 468000000.;
    geosatellites[6].lfac = 468000000.;
    geosatellites[6].coffhrv = 4576;
    geosatellites[6].loffhrv = 4576;
    geosatellites[6].cfachrv = 1872000000.;
    geosatellites[6].lfachrv = 1872000000.;

    geosatellites[6].spectrumlist << "VIS" << "IR4" << "IR3" << "IR1" << "IR2";
    geosatellites[6].spectrumvalueslist << "VIS 0.7" << "IR 3.7" << "IR 6.9" << "IR 10.8" << "IR 12.0";

    // Data Channel 3 & 4
    geosatellites[7].fullname = "GOES 15";
    geosatellites[7].shortname = "GOES_15";
    geosatellites[7].longitude = -135.2;
    geosatellites[7].longitudelimit1 = 0.0;
    geosatellites[7].longitudelimit2 = 0.0;
    geosatellites[7].protocol = "XRIT";
    geosatellites[7].rss = false;
    geosatellites[7].searchstring = "L-000-MSG3__-GOES15______";
    geosatellites[7].indexsearchstring = 0;
    geosatellites[7].filepattern = "L-???-??????-GOES15*%1-C_";
    geosatellites[7].imagewidth = 2816;
    geosatellites[7].imageheight = 3248;
    geosatellites[7].imagewidthhrv0 = 0;
    geosatellites[7].imageheighthrv0 = 0;
    geosatellites[7].imagewidthhrv1 = 0;
    geosatellites[7].imageheighthrv1 = 0;

    geosatellites[7].indexspectrum = 26;
    geosatellites[7].indexfilenbr = 36;
    geosatellites[7].lengthfilenbr = 6;
    geosatellites[7].indexdate = 46;
    geosatellites[7].lengthdate = 12; //YYYYMMDDHHmm

    geosatellites[7].spectrumhrv = "";
    geosatellites[7].spectrumvaluehrv = "";
    geosatellites[7].indexspectrumhrv = 0;
    geosatellites[7].indexfilenbrhrv = 0;
    geosatellites[7].lengthfilenbrhrv = 0;
    geosatellites[7].indexdatehrv = 0;
    geosatellites[7].lengthdatehrv = 0;

    geosatellites[7].color = false;
    geosatellites[7].maxsegments = 7;
    geosatellites[7].maxsegmentshrv = 0;
    geosatellites[7].startsegmentnbrtype0 = 0;
    geosatellites[7].startsegmentnbrhrvtype0 = 0;
    geosatellites[7].startsegmentnbrtype1 = 0;
    geosatellites[7].startsegmentnbrhrvtype1 = 0;
    geosatellites[7].prologfile = true;
    geosatellites[7].epilogfile = false;
    geosatellites[7].coff = 1408;
    geosatellites[7].loff = 1408;
    geosatellites[7].cfac = 585352820.;
    geosatellites[7].lfac = 585352820.;
    geosatellites[7].coffhrv = 0;
    geosatellites[7].loffhrv = 0;
    geosatellites[7].cfachrv = 0.;
    geosatellites[7].lfachrv = 0.;


    geosatellites[7].spectrumlist << "00_7" << "03_9" << "06_6" << "10_7";
    geosatellites[7].spectrumvalueslist << "VIS 0.7" << "IR 3.9" << "IR 6.6" << "IR 10.7";

    //
    geosatellites[8].fullname = "GOES 16";
    geosatellites[8].shortname = "GOES_16";
    geosatellites[8].longitude = -75.0;
    geosatellites[8].longitudelimit1 = -154.4;
    geosatellites[8].longitudelimit2 = -30.0;
    geosatellites[8].protocol = "netCDF";
    geosatellites[8].rss = false;
    geosatellites[8].searchstring = "OR_ABI";
    geosatellites[8].indexsearchstring = 0;
    geosatellites[8].imagewidth = 5424;
    geosatellites[8].imageheight = 5424;
    geosatellites[8].imagewidthhrv0 = 0;
    geosatellites[8].imageheighthrv0 = 0;
    geosatellites[8].imagewidthhrv1 = 0;
    geosatellites[8].imageheighthrv1 = 0;

    //0123456789012345678901234567890123456789012345678901234567890123456789012
    //OR_ABI-L1b-RadF-M4C01_G16_s20161811455312_e20161811500122_c20161811500175.nc

    geosatellites[8].indexspectrum = 18;
    geosatellites[8].indexfilenbr = 0;
    geosatellites[8].lengthfilenbr = 0;
    geosatellites[8].indexdate = 27;
    geosatellites[8].lengthdate = 11; //YYYYDDDHHmm

    geosatellites[8].spectrumhrv = "";
    geosatellites[8].spectrumvaluehrv = "";
    geosatellites[8].indexspectrumhrv = 0;
    geosatellites[8].indexfilenbrhrv = 0;
    geosatellites[8].lengthfilenbrhrv = 0;
    geosatellites[8].indexdatehrv = 0;
    geosatellites[8].lengthdatehrv = 0;

    geosatellites[8].color = true;
    geosatellites[8].maxsegments = 1;
    geosatellites[8].maxsegmentshrv = 0;
    geosatellites[8].startsegmentnbrtype0 = 0;
    geosatellites[8].startsegmentnbrhrvtype0 = 0;
    geosatellites[8].startsegmentnbrtype1 = 0;
    geosatellites[8].startsegmentnbrhrvtype1 = 0;
    geosatellites[8].prologfile = false;
    geosatellites[8].epilogfile = false;
    geosatellites[8].coff = 2712;
    geosatellites[8].loff = 2712;
    geosatellites[8].cfac = 1170000000.;
    geosatellites[8].lfac = 1170000000.;
    geosatellites[8].coffhrv = 0;
    geosatellites[8].loffhrv = 0;
    geosatellites[8].cfachrv = 0.;
    geosatellites[8].lfachrv = 0.;


    geosatellites[8].spectrumlist << "C01" << "C02" << "C03" << "C04" << "C05" << "C06" << "C07" << "C08" << "C09" << "C10" << "C11" << "C12" << "C13" << "C14" << "C15" << "C16";
    geosatellites[8].spectrumvalueslist << "0.47" << "0.64" << "0.86" << "1.37" << "1.61" << "2.24" << "3.89" << "6.17" << "6.93" << "7.34" << "8.44" << "9.61" << "10.33"  << "11.2"
                                        << "12.3" << "13.3";

    //E1B-TPG-1
    geosatellites[9].fullname = "Himawari 8";
    geosatellites[9].shortname = "H8";
    geosatellites[9].longitude = 140.7;
    geosatellites[9].longitudelimit1 = 92.0;
    geosatellites[9].longitudelimit2 = 250.0;
    geosatellites[9].protocol = "XRIT";
    geosatellites[9].rss = false;
    geosatellites[9].searchstring = "IMG_DK01";
    geosatellites[9].indexsearchstring = 0;
    geosatellites[9].filepattern = "IMG_DK01???_%1*";
    geosatellites[9].imagewidth = 5500;
    geosatellites[9].imageheight = 5500;
    geosatellites[9].imagewidthhrv0 = 0;
    geosatellites[9].imageheighthrv0 = 0;
    geosatellites[9].imagewidthhrv1 = 0;
    geosatellites[9].imageheighthrv1 = 0;

    geosatellites[9].indexspectrum = 8;
    geosatellites[9].indexfilenbr = 25;
    geosatellites[9].lengthfilenbr = 3;
    geosatellites[9].indexdate = 12;
    geosatellites[9].lengthdate = 11;

    geosatellites[9].spectrumhrv = "";
    geosatellites[9].spectrumvaluehrv = "";
    geosatellites[9].indexspectrumhrv = 0;
    geosatellites[9].indexfilenbrhrv = 0;
    geosatellites[9].lengthfilenbrhrv = 0;
    geosatellites[9].indexdatehrv = 0;
    geosatellites[9].lengthdatehrv = 0;

    geosatellites[9].color = true;
    geosatellites[9].maxsegments = 10;
    geosatellites[9].maxsegmentshrv = 0;
    geosatellites[9].startsegmentnbrtype0 = 0;
    geosatellites[9].startsegmentnbrhrvtype0 = 0;
    geosatellites[9].startsegmentnbrtype1 = 0;
    geosatellites[9].startsegmentnbrhrvtype1 = 0;
    geosatellites[9].prologfile = false;
    geosatellites[9].epilogfile = false;
    geosatellites[9].coff = 2750;
    geosatellites[9].loff = 2750;
    geosatellites[9].cfac = 1172050000.;
    geosatellites[9].lfac = 1172050000.;
    geosatellites[9].coffhrv = 0;
    geosatellites[9].loffhrv = 0;
    geosatellites[9].cfachrv = 0.;
    geosatellites[9].lfachrv = 0.;


    geosatellites[9].spectrumlist << "VIS" << "B04" << "B05" << "B06" << "IR4" << "IR3" << "B09" << "B10" << "B11" << "B12" << "IR1" << "B14" << "IR2" << "B16";
    geosatellites[9].spectrumvalueslist << "0.64" << "0.86" << "1.6" << "2.3" << "3.9" << "6.2" << "6.9" << "7.3" << "8.6" << "9.6" << "10.4" << "11.2" << "12.4" << "13.3";

    settingsgeo.beginWriteArray("geos");
    for (int i = 0; i < this->geosatellites.size(); ++i) {
        settingsgeo.setArrayIndex(i);
        settingsgeo.setValue("fullname", geosatellites.at(i).fullname);
        settingsgeo.setValue("shortname", geosatellites.at(i).shortname);
        settingsgeo.setValue("longitude", geosatellites.at(i).longitude);
        settingsgeo.setValue("protocol", geosatellites.at(i).protocol);
        settingsgeo.setValue("rss", geosatellites.at(i).rss);
        settingsgeo.setValue("searchstring", geosatellites.at(i).searchstring);
        settingsgeo.setValue("indexsearchstring", geosatellites.at(i).indexsearchstring);
        settingsgeo.setValue("filepattern", geosatellites.at(i).filepattern);
        settingsgeo.setValue("imagewidth", geosatellites.at(i).imagewidth);
        settingsgeo.setValue("imageheight", geosatellites.at(i).imageheight);
        settingsgeo.setValue("spectrumlist", geosatellites.at(i).spectrumlist);
        settingsgeo.setValue("spectrumvalueslist", geosatellites.at(i).spectrumvalueslist);
        settingsgeo.setValue("indexspectrum", geosatellites.at(i).indexspectrum);
        settingsgeo.setValue("indexfilenbr", geosatellites.at(i).indexfilenbr);
        settingsgeo.setValue("lengthfilenbr", geosatellites.at(i).lengthfilenbr);
        settingsgeo.setValue("indexdate", geosatellites.at(i).indexdate);
        settingsgeo.setValue("lengthdate", geosatellites.at(i).lengthdate);
        settingsgeo.setValue("spectrumhrv", geosatellites.at(i).spectrumhrv);
        settingsgeo.setValue("spectrumvaluehrv", geosatellites.at(i).spectrumvaluehrv);
        settingsgeo.setValue("indexspectrumhrv", geosatellites.at(i).indexspectrumhrv);
        settingsgeo.setValue("indexfilenbrhrv", geosatellites.at(i).indexfilenbrhrv);
        settingsgeo.setValue("lengthfilenbrhrv", geosatellites.at(i).lengthfilenbrhrv);
        settingsgeo.setValue("indexdatehrv", geosatellites.at(i).indexdatehrv);
        settingsgeo.setValue("lengthdatehrv", geosatellites.at(i).lengthdatehrv);

        settingsgeo.setValue("color", geosatellites.at(i).color);
        settingsgeo.setValue("maxsegments", geosatellites.at(i).maxsegments);
        settingsgeo.setValue("maxsegmentshrv", geosatellites.at(i).maxsegmentshrv);
        settingsgeo.setValue("startsegmenttype0", geosatellites.at(i).startsegmentnbrtype0);
        settingsgeo.setValue("startsegmenthrvtype0", geosatellites.at(i).startsegmentnbrhrvtype0);
        settingsgeo.setValue("startsegmenttype1", geosatellites.at(i).startsegmentnbrtype1);
        settingsgeo.setValue("startsegmenthrvtype1", geosatellites.at(i).startsegmentnbrhrvtype1);
    }
    settingsgeo.endArray();
}

void Options::deleteTleFile( QString sel )
{

  QStringList::Iterator its = tlelist.begin();
  QStringList strlistout;
  
  while( its != tlelist.end() )
  {
    if (*its != sel)
      strlistout << *its;
    ++its;
  }
  tlelist = strlistout;
  
}  

bool Options::addTleFile( QString sel )
{
  QStringList::Iterator its = tlelist.begin();
  bool thesame = false;
  while( its != tlelist.end() )
  {
    if (*its  == sel)
      thesame = true;
    ++its;
  }
  if(!thesame)
      tlelist << sel;
  return (!thesame);

}

void Options::deleteSegmentDirectory( QString sel )
{
  QStringList::Iterator its = segmentdirectorylist.begin();
  QStringList strlistout;

  while( its != segmentdirectorylist.end() )
  {
    if (*its != sel)
      strlistout << *its;
    ++its;
  }
  segmentdirectorylist = strlistout;

}

