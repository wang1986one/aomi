/*
	This file is a part of Awesomium, a library that makes it easy for 
	developers to embed web-content in their applications.

	Copyright (C) 2009 Adam J. Simmons

	Project Website:
	<http://princeofcode.com/awesomium.php>

	This library is free software; you can redistribute it and/or
	modify it under the terms of the GNU Lesser General Public
	License as published by the Free Software Foundation; either
	version 2.1 of the License, or (at your option) any later version.

	This library is distributed in the hope that it will be useful,
	but WITHOUT ANY WARRANTY; without even the implied warranty of
	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
	Lesser General Public License for more details.

	You should have received a copy of the GNU Lesser General Public
	License along with this library; if not, write to the Free Software
	Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 
	02110-1301 USA
*/

#ifndef __WINDOWLESS_PLUGIN_H__
#define __WINDOWLESS_PLUGIN_H__

#include "webkit/glue/webplugin_delegate.h"
#include "webkit/glue/webplugin.h"
#include "webkit/glue/plugins/plugin_instance.h"
#include "webkit/glue/plugins/plugin_lib.h"
#include "webkit/glue/plugins/plugin_stream_url.h"
#include "WebInputEvent.h"
#include "base/message_loop.h"
#include "base/timer.h"
#include "WebCore.h"
#include "webkit/glue/webcursor.h"
#include "webkit/api/public/WebInputEvent.h"

class WindowlessPlugin : public WebPluginDelegate
{
public:
	WebPlugin* plugin;
	scoped_refptr<NPAPI::PluginInstance> pluginInstance;
	std::string pluginURL;
	NPWindow window;
	bool needsSetWindow;
	gfx::NativeDrawingContext hdc;
#if defined(__APPLE__)
	NP_CGContext npCgContext;
	base::RepeatingTimer<WindowlessPlugin> pluginUpdateTimer;
#endif
	
	WindowlessPlugin(NPAPI::PluginInstance *pluginInstance);

	~WindowlessPlugin();

	void destroyInstance();

	static WindowlessPlugin* Create(const FilePath& path, const std::string& mime_type);

	// Initializes the plugin implementation with the given (UTF8) arguments.
	// Note that the lifetime of WebPlugin must be longer than this delegate.
	// If this function returns false the plugin isn't started and shouldn't be
	// called again.  If this method succeeds, then the WebPlugin is valid until
	// PluginDestroyed is called.
	// The load_manually parameter if true indicates that the plugin data would 
	// be passed from webkit. if false indicates that the plugin should download 
	// the data. This also controls whether the plugin is instantiated as a full 
	// page plugin (NP_FULL) or embedded (NP_EMBED)
	bool Initialize(const GURL& url, char** argn, char** argv, int argc, WebPlugin* plugin, bool load_manually);

	// Called when the WebPlugin is being destroyed.  This is a signal to the
	// delegate that it should tear-down the plugin implementation and not call
	// methods on the WebPlugin again.
	void PluginDestroyed();

	// Update the geometry of the plugin.  This is a request to move the plugin,
	// relative to its containing window, to the coords given by window_rect.
	// Its contents should be clipped to the coords given by clip_rect, which are
	// relative to the origin of the plugin window.
	void UpdateGeometry(const gfx::Rect& window_rect, const gfx::Rect& clip_rect);

	// Tells the plugin to paint the damaged rect.  The HDC is only used for
	// windowless plugins.
	void Paint(gfx::NativeDrawingContext hdc, const gfx::Rect& rect);

	// Tells the plugin to print itself.
	void Print(gfx::NativeDrawingContext hdc);

	// Informs the plugin that it now has focus.
	void SetFocus();

	// For windowless plugins, gives them a user event like mouse/keyboard.
	// Returns whether the event was handled.
	bool HandleEvent(NPEvent* event, WebCursor* cursor);

	// Gets the NPObject associated with the plugin for scripting.
	NPObject* GetPluginScriptableObject();

	// Receives notification about a resource load that the plugin initiated
	// for a frame.
	void DidFinishLoadWithReason(NPReason reason);
  
	// Returns the process id of the process that is running the plugin.
	int GetProcessId();

	// Returns the window handle for this plugin if it's a windowed plugin,
	// or NULL otherwise.
	gfx::NativeView GetWindowHandle() ;

	void FlushGeometryUpdates();

	// The result of the script execution is returned via this function.
	void SendJavaScriptStream(const std::string& url, const std::wstring& result,  bool success, bool notify_needed, intptr_t notify_data);

	// Receives notification about data being available. 
	void DidReceiveManualResponse(const GURL& url, const std::string& mime_type, const std::string& headers, uint32 expected_length, uint32 last_modified);

	// Receives the data.
	void DidReceiveManualData(const char* buffer, int length);

	// Indicates end of data load.
	void DidFinishManualLoading();
	// Indicates a failure in data receipt.
	void DidManualLoadFail();

	// Only Available after Initialize is called.
	FilePath GetPluginPath();

	// Only Supported when the plugin is the default plugin.
	void InstallMissingPlugin();

	// Creates a WebPluginResourceClient instance and returns the same.
	WebPluginResourceClient* CreateResourceClient(int resource_id, const GURL &url, bool notify_needed, intptr_t notify_data, intptr_t existing_stream);

	// Notifies the delegate about a Get/Post URL request getting routed
	void URLRequestRouted(const std::string&url, bool notify_needed, intptr_t notify_data);

	bool HandleInputEvent(const WebKit::WebInputEvent &,WebKit::WebCursorInfo *) ;

	void updatePlugin();
};

#endif
