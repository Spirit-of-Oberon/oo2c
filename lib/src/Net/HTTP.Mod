MODULE Net:HTTP;
(*  Some HTTP constants and convenience functions.
    Copyright (C) 2001  Michael van Acken

    This module is free software; you can redistribute it and/or
    modify it under the terms of the GNU Lesser General Public License
    as published by the Free Software Foundation; either version 2 of
    the License, or (at your option) any later version.

    This module is distributed in the hope that it will be useful, but
    WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
    Lesser General Public License for more details.

    You should have received a copy of the GNU Lesser General Public
    License along with OOC. If not, write to the Free Software Foundation,
    59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.
*)

IMPORT
  Object;
  
TYPE
  ResponseCode* = INTEGER;
  
CONST
  scContinue* = 100;
  (**Status code (100) indicating the client can continue.  *)
  scSwitchingProtocols* = 101;
  (**Status code (101) indicating the server is switching protocols according
     to @samp{Upgrade} header.  *)
  
  scOk* = 200;
  (**Status code (200) indicating the request succeeded normally.  *)
  scCreated* = 201;
  (**Status code (201) indicating the request succeeded and created a new
     resource on the server.  *)
  scAccepted* = 202;
  (** Status code (202) indicating that a request was accepted for processing,
     but was not completed.  *)
  scNonAuthoritativeInformation* = 203;
  (**Status code (203) indicating that the meta information presented by the
     client did not originate from the server.  *)
  scNoContent* = 204;
  (**Status code (204) indicating that the request succeeded but that there was
     no new information to return.  *)
  scResetContent* = 205;
  (**Status code (205) indicating that the agent @strong{should} reset the
     document view which caused the request to be sent.  *)
  scPartialContent* = 206;
  (**Status code (206) indicating that the server has fulfilled the partial GET
     request for the resource.  *)
  
  scMultipleChoices* = 300;
  (**Status code (300) indicating that the requested resource corresponds to
     any one of a set of representations, each with its own specific location.  *)
  scMovedPermanently* = 301;
  (**Status code (301) indicating that the resource has permanently moved to a
     new location, and that future references should use a new URI with their
     requests.  *)
  scMovedTemporarily* = 302;
  (**Status code (302) indicating that the resource has temporarily moved to
     another location, but that future references should still use the original
     URI to access the resource.  *)
  scSeeOther* = 303;
  (**Status code (303) indicating that the response to the request can be found
     under a different URI.  *)
  scNotModified* = 304;
  (**Status code (304) indicating that a conditional GET operation found that
     the resource was available and not modified.  *)
  scUseProxy* = 305;
  (**Status code (305) indicating that the requested resource @strong{MUST} be
     accessed through the proxy given by the @samp{Location} field.  *)
  
  scBadRequest* = 400;
  (**Status code (400) indicating the request sent by the client was
     syntactically incorrect.  *)
  scUnauthorized* = 401;
  (**Status code (401) indicating that the request requires HTTP
     authentication.  *)
  scPaymentRequired* = 402;
  (**Status code (402) reserved for future use.  *)
  scForbidden* = 403;
  (**Status code (403) indicating the server understood the request but
     refused to fulfill it.  *)
  scNotFound* = 404;
  (**Status code (404) indicating that the requested resource is not available.  *)
  scMethodNotAllowed* = 405;
  (**Status code (405) indicating that the method specified in the Request-Line
     is not allowed for the resource identified by the Request-URI.  *)
  scNotAcceptable* = 406;
  (**Status code (406) indicating that the resource identified by the request
     is only capable of generating response entities which have content
     characteristics not acceptable according to the accept headerssent in the
     request.  *)
  scProxyAuthenticationRequired* = 407;
  (**Status code (407) indicating that the client @strong{must} first
     authenticate itself with the proxy.  *)
  scRequestTimeout* = 408;
  (**Status code (408) indicating that the client did not produce a
     requestwithin the time that the server was prepared to wait.  *)
  scConflict* = 409;
  (**Status code (409) indicating that the request could not be completed due
     to a conflict with the current state of the resource.  *)
  scGone* = 410;
  (**Status code (410) indicating that the resource is no longer available at
     the server and no forwarding address is known.  *)
  scLengthRequired* = 411;
  (**Status code (411) indicating that the request cannot be handled without a
     defined @samp{Content-Length}.  *)
  scPreconditionFailed* = 412;
  (**Status code (412) indicating that the precondition given in one or more of
     the request-header fields evaluated to false when it was tested on the
     server.  *)
  scRequestEntityTooLarge* = 413;
  (**Status code (413) indicating that the server is refusing to process the
     request because the request entity is larger than the server is willing or
     able to process.  *)
  scRequestURITooLong* = 414;
  (**Status code (414) indicating that the server is refusing to service the
     request because the Request-URI is longer than the server is willing to
     interpret.  *)
  scUnsupportedMediaType* = 415;
  (**Status code (415) indicating that the server is refusing to service the
     request because the entity of the request is in a format not supported by
     the requested resource for the requested method.  *)
  
  scInternalServerError* = 500;
  (**Status code (500) indicating an error inside the HTTP server which
     prevented it from fulfilling the request.  *)
  scNotImplemented* = 501;
  (**Status code (501) indicating the HTTP server does not support the
     functionality needed to fulfill the request.  *)
  scBadGateway* = 502;
  (**Status code (502) indicating that the HTTP server received an invalid
     response from a server it consulted when acting as a proxy or gateway.  *)
  scServiceUnavailable* = 503;
  (**Status code (503) indicating that the HTTP server is temporarily
     overloaded, and unable to handle the request.  *)
  scGatewayTimeout* = 504;
  (**Status code (504) indicating that the server did not receive a timely
     response from the upstream server while acting as a gateway or proxy.  *)
  scHTTPVersionNotSupported* = 505;
  (**Status code (505) indicating that the server does not support or refuses
     to support the HTTP protocol version that was used in the request message.  *)


TYPE
  MethodCode* = SHORTINT;

CONST
  methodUnknown* = -1;
  methodGET* = 0;
  methodPOST* = 1;


PROCEDURE GetMessage* (code: ResponseCode; VAR short, long: ARRAY OF CHAR);
  BEGIN
    CASE code OF
    | scOk:
      COPY ("OK", short);
      COPY ("Request fulfilled, document follows", long);
    | scBadRequest:
      COPY ("Bad Request", short);
      COPY ("Bad request syntax or unsupported method", long);
    | scNotFound:
      COPY ("Not found", short);
      COPY ("Nothing matches the given URI", long);
    | scNotImplemented:
      COPY ("Not implemented", short);
      COPY ("Request method is not implemented", long);
    ELSE
      COPY ("", short); COPY ("", long)
    END
  END GetMessage;

PROCEDURE GetMethodCode* (method: Object.String): MethodCode;
  BEGIN
    IF method.Equals(Object.NewLatin1("GET")) THEN
      RETURN methodGET
    ELSIF method.Equals(Object.NewLatin1("POST")) THEN
      RETURN methodPOST
    ELSE
      RETURN methodUnknown
    END
  END GetMethodCode;

END Net:HTTP.
